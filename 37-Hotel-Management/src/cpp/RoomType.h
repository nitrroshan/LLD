#pragma once
#include <string>

// The room categories, each with a nightly base price.
enum class RoomType { Single, Double, Suite, Deluxe };

inline int base_price(RoomType type) {
    switch (type) {
        case RoomType::Single: return 100;
        case RoomType::Double: return 150;
        case RoomType::Suite:  return 300;
        case RoomType::Deluxe: return 500;
    }
    return 0;
}

inline std::string to_string(RoomType type) {
    switch (type) {
        case RoomType::Single: return "Single";
        case RoomType::Double: return "Double";
        case RoomType::Suite:  return "Suite";
        case RoomType::Deluxe: return "Deluxe";
    }
    return "?";
}
