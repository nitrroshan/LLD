#pragma once

// State — the game's status. Governs whether further moves are allowed.
class GameState {
public:
    virtual ~GameState() = default;
    virtual bool is_game_over() const = 0;
    virtual const char* name() const = 0;
};
