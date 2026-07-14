#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "Board.h"
#include "Piece.h"
#include "PieceFactory.h"
#include "MoveCommand.h"
#include "GameState.h"
#include "GameStates.h"
#include "GameObserver.h"
#include "Color.h"
#include "PieceType.h"
#include "Position.h"

// Coordinator — owns the board, turn order, status (State), observers, and the
// move history (Command stack). Validates/applies moves, detects
// check/checkmate/stalemate, and supports undo.
class Game {
    Board board_;
    std::vector<GameObserver*> observers_;
    std::vector<std::unique_ptr<MoveCommand>> history_;
    Color current_turn_ = Color::White;
    GameState* state_ = &ActiveState::instance();

public:
    Game() { setup_standard_board(); }

    void add_observer(GameObserver* observer) { observers_.push_back(observer); }

    bool make_move(const Position& from, const Position& to) {
        if (state_->is_game_over()) {
            std::cout << "  Game is over (" << state_->name() << ")\n";
            return false;
        }
        Piece* piece = board_.get_piece(from);
        if (!piece || piece->color() != current_turn_) {
            std::cout << "  No " << to_string(current_turn_) << " piece at " << from.to_string() << "\n";
            return false;
        }
        Piece* target = board_.get_piece(to);
        if (target && target->color() == current_turn_) {
            std::cout << "  Cannot capture your own piece\n";
            return false;
        }
        if (!piece->can_move(board_, from, to)) {
            std::cout << "  Illegal move: " << from.to_string() << "->" << to.to_string() << "\n";
            return false;
        }

        // Simulate to ensure the move doesn't leave our own king in check.
        auto command = std::make_unique<MoveCommand>(board_, from, to);
        command->execute();
        if (board_.is_square_attacked(board_.find_king(current_turn_), opposite(current_turn_))) {
            command->undo();
            std::cout << "  Illegal: move would leave your king in check\n";
            return false;
        }

        // Legal — commit.
        for (auto* o : observers_) o->on_move(from, to, board_.get_piece(to), command->captured_view());
        history_.push_back(std::move(command));

        current_turn_ = opposite(current_turn_);
        update_status_for_side_to_move();
        return true;
    }

    void undo() {
        if (history_.empty()) {
            std::cout << "  Nothing to undo\n";
            return;
        }
        MoveCommand* last = history_.back().get();
        Position from = last->from(), to = last->to();
        last->undo();
        history_.pop_back();
        current_turn_ = opposite(current_turn_);
        state_ = &ActiveState::instance();
        std::cout << "  Undid " << to.to_string() << "->" << from.to_string() << "\n";
    }

    const Board& board() const { return board_; }
    GameState* state() const { return state_; }
    Color current_turn() const { return current_turn_; }

private:
    void update_status_for_side_to_move() {
        bool in_check = board_.is_square_attacked(board_.find_king(current_turn_), opposite(current_turn_));
        bool has_move = has_any_legal_move(current_turn_);

        if (in_check && !has_move) {
            state_ = &CheckmateState::instance();
            for (auto* o : observers_) o->on_checkmate(opposite(current_turn_));
        } else if (!in_check && !has_move) {
            state_ = &StalemateState::instance();
            for (auto* o : observers_) o->on_stalemate();
        } else if (in_check) {
            state_ = &CheckState::instance();
            for (auto* o : observers_) o->on_check(current_turn_);
        } else {
            state_ = &ActiveState::instance();
        }
    }

    bool has_any_legal_move(Color color) {
        for (int r = 0; r < 8; r++)
            for (int c = 0; c < 8; c++) {
                Position from{r, c};
                Piece* piece = board_.get_piece(from);
                if (!piece || piece->color() != color) continue;
                for (int tr = 0; tr < 8; tr++)
                    for (int tc = 0; tc < 8; tc++) {
                        Position to{tr, tc};
                        Piece* target = board_.get_piece(to);
                        if (target && target->color() == color) continue;
                        if (!piece->can_move(board_, from, to)) continue;
                        MoveCommand trial(board_, from, to);
                        trial.execute();
                        bool safe = !board_.is_square_attacked(board_.find_king(color), opposite(color));
                        trial.undo();
                        if (safe) return true;
                    }
            }
        return false;
    }

    void setup_standard_board() {
        for (int c = 0; c < 8; c++) {
            board_.set_piece({1, c}, PieceFactory::create(Color::White, PieceType::Pawn));
            board_.set_piece({6, c}, PieceFactory::create(Color::Black, PieceType::Pawn));
        }
        PieceType order[8] = {
            PieceType::Rook, PieceType::Knight, PieceType::Bishop, PieceType::Queen,
            PieceType::King, PieceType::Bishop, PieceType::Knight, PieceType::Rook
        };
        for (int c = 0; c < 8; c++) {
            board_.set_piece({0, c}, PieceFactory::create(Color::White, order[c]));
            board_.set_piece({7, c}, PieceFactory::create(Color::Black, order[c]));
        }
    }
};
