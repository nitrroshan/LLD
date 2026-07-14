#pragma once
#include <iostream>
#include "RoomState.h"
#include "Room.h"

// Concrete states as stateless singletons. Declarations first, then out-of-line
// inline definitions so each state can reference its siblings' singletons.

class AvailableState : public RoomState {
public:
    static AvailableState& instance();
    void book(Room& room) override;
    void check_in(Room& room) override;
    void check_out(Room& room) override;
    const char* name() const override { return "AVAILABLE"; }
};

class BookedState : public RoomState {
public:
    static BookedState& instance();
    void book(Room& room) override;
    void check_in(Room& room) override;
    void check_out(Room& room) override;
    const char* name() const override { return "BOOKED"; }
};

class OccupiedState : public RoomState {
public:
    static OccupiedState& instance();
    void book(Room& room) override;
    void check_in(Room& room) override;
    void check_out(Room& room) override;
    const char* name() const override { return "OCCUPIED"; }
};

// --- singleton accessors (Meyer's singletons) ---
inline AvailableState& AvailableState::instance() { static AvailableState s; return s; }
inline BookedState&    BookedState::instance()    { static BookedState s; return s; }
inline OccupiedState&  OccupiedState::instance()  { static OccupiedState s; return s; }

// --- Available transitions ---
inline void AvailableState::book(Room& room) {
    std::cout << "    Room " << room.number() << " booked\n";
    room.set_state(&BookedState::instance());
}
inline void AvailableState::check_in(Room& room) {
    std::cout << "    Room " << room.number() << " is not booked yet\n";
}
inline void AvailableState::check_out(Room& room) {
    std::cout << "    Room " << room.number() << " is not occupied\n";
}

// --- Booked transitions ---
inline void BookedState::book(Room& room) {
    std::cout << "    Room " << room.number() << " is already booked\n";
}
inline void BookedState::check_in(Room& room) {
    std::cout << "    Checked in to room " << room.number() << "\n";
    room.set_state(&OccupiedState::instance());
}
inline void BookedState::check_out(Room& room) {
    std::cout << "    Guest hasn't checked in to room " << room.number() << "\n";
}

// --- Occupied transitions ---
inline void OccupiedState::book(Room& room) {
    std::cout << "    Room " << room.number() << " is occupied\n";
}
inline void OccupiedState::check_in(Room& room) {
    std::cout << "    Already checked in to room " << room.number() << "\n";
}
inline void OccupiedState::check_out(Room& room) {
    std::cout << "    Checked out of room " << room.number() << "\n";
    room.set_state(&AvailableState::instance());
}
