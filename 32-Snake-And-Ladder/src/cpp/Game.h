#pragma once
#include <vector>
#include "Board.h"
#include "Dice.h"
#include "Player.h"
#include "GameEventListener.h"
#include "GameStatus.h"

// Runs the game: rotates players, rolls the die, applies jumps, and emits events
// to observers until someone lands exactly on the final cell.
class Game {
    Board& board_;
    Dice& dice_;
    std::vector<Player*> players_;
    std::vector<GameEventListener*> listeners_;
    int current_player_ = 0;
    GameStatus status_ = GameStatus::Running;

    void notify_move(const Player& p, int from, int to, int dice) {
        for (auto* l : listeners_) l->on_move(p, from, to, dice);
    }
    void notify_jump(const Player& p, JumpType type, int from, int to) {
        for (auto* l : listeners_) l->on_jump(p, type, from, to);
    }
    void notify_skip(const Player& p, int dice) {
        for (auto* l : listeners_) l->on_skip(p, dice);
    }
    void notify_win(const Player& p) {
        for (auto* l : listeners_) l->on_win(p);
    }

public:
    Game(Board& board, Dice& dice, std::vector<Player*> players)
        : board_(board), dice_(dice), players_(std::move(players)) {}

    void add_listener(GameEventListener* listener) { listeners_.push_back(listener); }
    GameStatus status() const { return status_; }

    void play_turn() {
        Player* player = players_[current_player_];
        int dice = dice_.roll();
        int from = player->position();
        int target = from + dice;

        if (target > board_.size()) {
            notify_skip(*player, dice);
        } else {
            Jump* jump = board_.get_jump(target);
            int destination = jump ? jump->end() : target;
            player->set_position(destination);
            notify_move(*player, from, target, dice);
            if (jump) {
                notify_jump(*player, jump->type(), target, destination);
            }
            if (destination == board_.size()) {
                notify_win(*player);
                status_ = GameStatus::Finished;
                return;
            }
        }
        current_player_ = (current_player_ + 1) % static_cast<int>(players_.size());
    }

    void play(int max_turns) {
        int turn = 0;
        while (status_ == GameStatus::Running && turn < max_turns) {
            play_turn();
            turn++;
        }
    }
};
