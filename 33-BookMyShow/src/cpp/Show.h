#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <mutex>
#include "Movie.h"
#include "Screen.h"
#include "SeatStatus.h"

// A movie on a screen at a time. Owns the PER-SHOW seat status and the seat
// locking that prevents double-booking. A mutex guards the critical section.
class Show {
    std::string id_;
    Movie* movie_;
    Screen* screen_;
    std::string start_time_;
    std::unordered_map<std::string, SeatStatus> status_;
    std::unordered_map<std::string, std::string> locked_by_;
    std::mutex mutex_;

public:
    Show(std::string id, Movie* movie, Screen* screen, std::string start_time)
        : id_(std::move(id)), movie_(movie), screen_(screen), start_time_(std::move(start_time)) {
        for (const std::string& seat_id : screen_->seat_ids()) {
            status_[seat_id] = SeatStatus::Available;
        }
    }

    const std::string& id() const { return id_; }
    Movie* movie() const { return movie_; }
    Screen* screen() const { return screen_; }
    const std::string& start_time() const { return start_time_; }

    // Atomically lock all requested seats, or none.
    bool lock_seats(const std::vector<std::string>& seat_ids, const std::string& user_id) {
        std::lock_guard<std::mutex> guard(mutex_);
        for (const auto& seat_id : seat_ids) {
            auto it = status_.find(seat_id);
            if (it == status_.end() || it->second != SeatStatus::Available) {
                return false;
            }
        }
        for (const auto& seat_id : seat_ids) {
            status_[seat_id] = SeatStatus::Locked;
            locked_by_[seat_id] = user_id;
        }
        return true;
    }

    void confirm_seats(const std::vector<std::string>& seat_ids, const std::string& user_id) {
        std::lock_guard<std::mutex> guard(mutex_);
        for (const auto& seat_id : seat_ids) {
            if (locked_by_[seat_id] == user_id) {
                status_[seat_id] = SeatStatus::Booked;
                locked_by_.erase(seat_id);
            }
        }
    }

    void release_seats(const std::vector<std::string>& seat_ids, const std::string& user_id) {
        std::lock_guard<std::mutex> guard(mutex_);
        for (const auto& seat_id : seat_ids) {
            if (locked_by_[seat_id] == user_id) {
                status_[seat_id] = SeatStatus::Available;
                locked_by_.erase(seat_id);
            }
        }
    }

    bool is_sold_out() {
        std::lock_guard<std::mutex> guard(mutex_);
        for (const auto& entry : status_) {
            if (entry.second == SeatStatus::Available) return false;
        }
        return true;
    }

    int available_count() {
        std::lock_guard<std::mutex> guard(mutex_);
        int count = 0;
        for (const auto& entry : status_) {
            if (entry.second == SeatStatus::Available) count++;
        }
        return count;
    }
};
