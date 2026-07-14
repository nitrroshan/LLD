#pragma once
#include <string>
#include <set>
#include <vector>
#include <iterator>
#include <iostream>
#include "Direction.h"
#include "ElevatorStatus.h"
#include "Door.h"
#include "ElevatorObserver.h"

// Elevator — moves between floors serving its target stops using the LOOK
// algorithm, controls its door, and notifies observers on every change.
class Elevator {
    std::string id_;
    int current_floor_;
    Direction direction_ = Direction::Up;
    ElevatorStatus status_ = ElevatorStatus::Idle;
    std::set<int> targets_;
    Door door_;
    std::vector<ElevatorObserver*> observers_;

    void notify_observers() {
        for (auto* observer : observers_) {
            observer->update(*this);
        }
    }

    // LOOK: keep going in the current direction; reverse only when exhausted.
    // Precondition: current_floor_ is NOT itself a target.
    int pick_next_target() const {
        if (direction_ == Direction::Up) {
            auto up = targets_.lower_bound(current_floor_);   // first > current
            if (up != targets_.end()) {
                return *up;
            }
            return *std::prev(targets_.end());                // largest below
        } else {
            auto it = targets_.lower_bound(current_floor_);
            if (it != targets_.begin()) {
                return *std::prev(it);                        // largest below
            }
            return *targets_.begin();                         // smallest above
        }
    }

    void arrive() {
        status_ = ElevatorStatus::DoorsOpen;
        door_.open();
        std::cout << "  [" << id_ << "] arrived at floor " << current_floor_ << ", doors open\n";
        targets_.erase(current_floor_);
        notify_observers();
        door_.close();
        if (targets_.empty()) {
            status_ = ElevatorStatus::Idle;
            direction_ = Direction::Idle;
        } else {
            status_ = ElevatorStatus::Moving;
        }
    }

public:
    Elevator(std::string id, int start_floor)
        : id_(std::move(id)), current_floor_(start_floor) {}

    const std::string& id() const { return id_; }
    int current_floor() const { return current_floor_; }
    Direction direction() const { return direction_; }
    ElevatorStatus status() const { return status_; }
    int target_count() const { return static_cast<int>(targets_.size()); }
    bool is_idle() const { return targets_.empty(); }

    void add_target(int floor) { targets_.insert(floor); }
    void register_observer(ElevatorObserver* observer) { observers_.push_back(observer); }

    void step() {
        if (targets_.empty()) {
            if (status_ != ElevatorStatus::Idle) {
                status_ = ElevatorStatus::Idle;
                direction_ = Direction::Idle;
                notify_observers();
            }
            return;
        }

        if (targets_.count(current_floor_)) {
            arrive();
            return;
        }

        int next = pick_next_target();
        if (next > current_floor_) {
            current_floor_++;
            direction_ = Direction::Up;
        } else {
            current_floor_--;
            direction_ = Direction::Down;
        }
        status_ = ElevatorStatus::Moving;
        notify_observers();

        if (targets_.count(current_floor_)) {
            arrive();
        }
    }
};
