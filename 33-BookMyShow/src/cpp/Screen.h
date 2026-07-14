#pragma once
#include <string>
#include <map>
#include <vector>
#include "Seat.h"

// A screen owns the seat layout (ids + types). Per-show availability lives in Show.
class Screen {
    std::string id_;
    std::string name_;
    std::map<std::string, Seat> seats_;   // ordered for stable iteration

public:
    Screen(std::string id, std::string name)
        : id_(std::move(id)), name_(std::move(name)) {}

    const std::string& id() const { return id_; }
    const std::string& name() const { return name_; }

    void add_seat(const Seat& seat) {
        seats_.emplace(seat.id(), seat);
    }

    Seat* get_seat(const std::string& seat_id) {
        auto it = seats_.find(seat_id);
        return it != seats_.end() ? &it->second : nullptr;
    }

    std::vector<std::string> seat_ids() const {
        std::vector<std::string> ids;
        for (const auto& entry : seats_) ids.push_back(entry.first);
        return ids;
    }
};
