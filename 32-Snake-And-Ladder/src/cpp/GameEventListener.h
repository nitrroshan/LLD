#pragma once
#include "Player.h"
#include "JumpType.h"

// Observer — reacts to game events. The game notifies listeners without knowing
// what they do (log, count, record, display).
class GameEventListener {
public:
    virtual ~GameEventListener() = default;
    virtual void on_move(const Player& player, int from, int to, int dice_value) = 0;
    virtual void on_jump(const Player& player, JumpType type, int from, int to) = 0;
    virtual void on_skip(const Player& player, int dice_value) = 0;
    virtual void on_win(const Player& player) = 0;
};
