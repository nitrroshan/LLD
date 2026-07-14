#pragma once
#include <string>
#include "RoomType.h"
#include "RoomState.h"

// A hotel room. Holds its type and amenities, and delegates all lifecycle
// actions to its current State (a shared singleton). The initial state is set
// by the RoomFactory (which knows the concrete state classes).
class Room {
    std::string number_;
    RoomType type_;
    std::string amenities_;
    RoomState* state_ = nullptr;   // points at a shared state singleton

public:
    Room(std::string number, RoomType type, std::string amenities)
        : number_(std::move(number)), type_(type), amenities_(std::move(amenities)) {}

    // Lifecycle actions — delegate to the current state.
    void book()      { state_->book(*this); }
    void check_in()  { state_->check_in(*this); }
    void check_out() { state_->check_out(*this); }

    void set_state(RoomState* state) { state_ = state; }
    const std::string& number() const { return number_; }
    RoomType type() const { return type_; }
    const std::string& amenities() const { return amenities_; }
    const char* state_name() const { return state_->name(); }
};
