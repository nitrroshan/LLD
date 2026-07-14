#pragma once
#include <memory>
#include <string>
#include "Room.h"
#include "RoomStates.h"
#include "RoomType.h"

// Factory — builds a room with type-specific amenities and sets its initial
// (Available) state. Being here (where the concrete states are complete) keeps
// Room.h free of any dependency on the concrete state classes.
class RoomFactory {
public:
    static std::unique_ptr<Room> create(RoomType type, const std::string& number) {
        std::string amenities;
        switch (type) {
            case RoomType::Single: amenities = "WiFi, TV"; break;
            case RoomType::Double: amenities = "WiFi, TV, Minibar"; break;
            case RoomType::Suite:  amenities = "WiFi, TV, Minibar, Jacuzzi"; break;
            case RoomType::Deluxe: amenities = "WiFi, TV, Minibar, Jacuzzi, Balcony"; break;
        }
        auto room = std::make_unique<Room>(number, type, amenities);
        room->set_state(&AvailableState::instance());   // start Available
        return room;
    }
};
