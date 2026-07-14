#pragma once

class Room;

// State — each concrete state defines how the three room actions behave and
// what transition follows. Illegal actions are refused by the current state.
// States are stateless singletons, so they take the Room& as a parameter.
class RoomState {
public:
    virtual ~RoomState() = default;
    virtual void book(Room& room) = 0;
    virtual void check_in(Room& room) = 0;
    virtual void check_out(Room& room) = 0;
    virtual const char* name() const = 0;
};
