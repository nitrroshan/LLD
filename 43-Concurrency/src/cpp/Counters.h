#pragma once
#include <mutex>
#include <atomic>

// Three counters for the race demo: unsafe (plain int++), mutex-guarded, and
// atomic. Only the unsafe one loses updates (data race = undefined behavior).

class UnsafeCounter {
    int count_ = 0;
public:
    void increment() { count_++; }   // NOT atomic — data race under threads
    int get() const { return count_; }
};

class MutexCounter {
    int count_ = 0;
    mutable std::mutex mtx_;
public:
    void increment() {
        std::lock_guard<std::mutex> lock(mtx_);   // RAII: unlocks on scope exit
        count_++;
    }
    int get() const {
        std::lock_guard<std::mutex> lock(mtx_);
        return count_;
    }
};

class AtomicCounter {
    std::atomic<int> count_{0};
public:
    void increment() { count_.fetch_add(1); }   // atomic RMW, lock-free
    int get() const { return count_.load(); }
};
