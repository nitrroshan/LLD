#pragma once
#include <iostream>
#include "Board.h"
#include "Player.h"
#include "GameStatus.h"

// Orchestrates the game: alternates players, applies moves, updates status.
class Game {
    Board board_;
    Player* players_[2];
    int current_ = 0;
    GameStatus status_ = GameStatus::InProgress;

    void update_status() {
        Symbol winner = board_.get_winner();
        if (winner == Symbol::X) {
            status_ = GameStatus::XWins;
        } else if (winner == Symbol::O) {
            status_ = GameStatus::OWins;
        } else if (board_.is_full()) {
            status_ = GameStatus::Draw;
        }
    }

    void announce_result() {
        switch (status_) {
            case GameStatus::XWins:
                std::cout << "  Result: " << players_[0]->name() << " (X) wins!\n"; break;
            case GameStatus::OWins:
                std::cout << "  Result: " << players_[1]->name() << " (O) wins!\n"; break;
            case GameStatus::Draw:
                std::cout << "  Result: draw.\n"; break;
            default:
                std::cout << "  Result: game ended early.\n";
        }
    }

public:
    Game(Board board, Player& player_x, Player& player_o)
        : board_(std::move(board)), players_{&player_x, &player_o} {}

    GameStatus status() const { return status_; }

    void play() {
        board_.display();
        while (status_ == GameStatus::InProgress) {
            Player* player = players_[current_];
            Move move = player->make_move(board_);
            if (!board_.is_valid(move)) {
                std::cout << "  " << player->name() << " made an invalid move, skipping\n";
                break;
            }
            board_.place_mark(move, player->symbol());
            std::cout << "  " << player->name() << " (" << to_string(player->symbol())
                      << ") plays (" << move.row << ", " << move.col << ")\n";
            board_.display();

            update_status();
            current_ = 1 - current_;
        }
        announce_result();
    }
};
