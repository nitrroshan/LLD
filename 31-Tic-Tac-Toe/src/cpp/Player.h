#pragma once
#include <string>
#include <memory>
#include "Symbol.h"
#include "Move.h"
#include "MoveStrategy.h"
#include "Board.h"

// A player is a name + symbol + a move strategy (which it owns). "Human vs AI"
// is just two players with different strategies.
class Player {
    std::string name_;
    Symbol symbol_;
    std::unique_ptr<MoveStrategy> strategy_;

public:
    Player(std::string name, Symbol symbol, std::unique_ptr<MoveStrategy> strategy)
        : name_(std::move(name)), symbol_(symbol), strategy_(std::move(strategy)) {}

    const std::string& name() const { return name_; }
    Symbol symbol() const { return symbol_; }

    Move make_move(const Board& board) {
        return strategy_->choose_move(board, symbol_);
    }
};
