#pragma once
#include <string>

// The vehicle categories, each with a per-km rate.
enum class VehicleType { Bike, Auto, Sedan, Suv };

inline double rate_per_km(VehicleType t) {
    switch (t) {
        case VehicleType::Bike:  return 5;
        case VehicleType::Auto:  return 8;
        case VehicleType::Sedan: return 12;
        case VehicleType::Suv:   return 18;
    }
    return 0;
}

inline std::string to_string(VehicleType t) {
    switch (t) {
        case VehicleType::Bike:  return "Bike";
        case VehicleType::Auto:  return "Auto";
        case VehicleType::Sedan: return "Sedan";
        case VehicleType::Suv:   return "SUV";
    }
    return "?";
}
