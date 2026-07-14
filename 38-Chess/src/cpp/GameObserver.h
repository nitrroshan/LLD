#pragma once
#include "Color.h"
#include "Position.h"
#include "Piece.h"

// Observer — reacts to game events without the game knowing the listener type.
class GameObserver {
public:
    virtual ~GameObserver() = default;
    virtual void on_move(const Position& from, const Position& to, Piece* moved, Piece* captured) = 0;
    virtual void on_check(Color in_check) = 0;
    virtual void on_checkmate(Color winner) = 0;
    virtual void on_stalemate() = 0;
};
