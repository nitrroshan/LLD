#pragma once

// Vehicle types. The underlying value doubles as the size used for fit logic.
enum class VehicleType { Motorcycle = 1, Car = 2, Truck = 3 };

inline int size_of(VehicleType type) {
    return static_cast<int>(type);
}

inline const char* to_string(VehicleType type) {
    switch (type) {
        case VehicleType::Motorcycle: return "MOTORCYCLE";
        case VehicleType::Car:        return "CAR";
        case VehicleType::Truck:      return "TRUCK";
    }
    return "?";
}
