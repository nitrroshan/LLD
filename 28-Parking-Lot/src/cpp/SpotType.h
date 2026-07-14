#pragma once

// Spot sizes, ordered so a larger spot can hold a smaller vehicle.
enum class SpotType { Small = 1, Medium = 2, Large = 3 };

inline int size_of(SpotType type) {
    return static_cast<int>(type);
}
