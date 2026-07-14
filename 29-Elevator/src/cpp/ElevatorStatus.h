#pragma once

// The elevator's operating state. Modeled as an enum here; refactoring into
// State-pattern classes (Ch25) is the easy assignment.
enum class ElevatorStatus { Idle, Moving, DoorsOpen };

inline const char* to_string(ElevatorStatus s) {
    switch (s) {
        case ElevatorStatus::Idle:      return "IDLE";
        case ElevatorStatus::Moving:    return "MOVING";
        case ElevatorStatus::DoorsOpen: return "DOORS_OPEN";
    }
    return "?";
}
