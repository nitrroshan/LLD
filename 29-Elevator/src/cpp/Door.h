#pragma once

// The car door. Kept minimal.
class Door {
    bool open_ = false;

public:
    void open() { open_ = true; }
    void close() { open_ = false; }
    bool is_open() const { return open_; }
};
