#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>
#include <cstddef>

// A bounded blocking queue — the heart of the Producer-Consumer pattern.
// put() blocks when full; take() blocks when empty. wait(lock, predicate)
// releases the lock while sleeping and re-checks on wakeup (guards against
// spurious wakeups).
template <class T>
class BlockingBuffer {
    std::queue<T> q_;
    mutable std::mutex mtx_;
    std::condition_variable not_empty_;
    std::condition_variable not_full_;
    std::size_t capacity_;

public:
    explicit BlockingBuffer(std::size_t capacity) : capacity_(capacity) {}

    void put(T item) {
        std::unique_lock<std::mutex> lock(mtx_);
        not_full_.wait(lock, [&] { return q_.size() < capacity_; });   // block if full
        q_.push(std::move(item));
        not_empty_.notify_one();
    }

    T take() {
        std::unique_lock<std::mutex> lock(mtx_);
        not_empty_.wait(lock, [&] { return !q_.empty(); });            // block if empty
        T item = std::move(q_.front());
        q_.pop();
        not_full_.notify_one();
        return item;
    }
};
