#pragma once
#include "GameState.h"

// Concrete game states as singletons.

class ActiveState : public GameState {
public:
    static ActiveState& instance() { static ActiveState s; return s; }
    bool is_game_over() const override { return false; }
    const char* name() const override { return "ACTIVE"; }
};

class CheckState : public GameState {
public:
    static CheckState& instance() { static CheckState s; return s; }
    bool is_game_over() const override { return false; }
    const char* name() const override { return "CHECK"; }
};

class CheckmateState : public GameState {
public:
    static CheckmateState& instance() { static CheckmateState s; return s; }
    bool is_game_over() const override { return true; }
    const char* name() const override { return "CHECKMATE"; }
};

class StalemateState : public GameState {
public:
    static StalemateState& instance() { static StalemateState s; return s; }
    bool is_game_over() const override { return true; }
    const char* name() const override { return "STALEMATE"; }
};
