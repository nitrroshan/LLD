#pragma once
#include "Device.h"
#include <iostream>

// Abstraction — high-level remote control operations
class Remote {
protected:
    Device& device_;  // ← THE BRIDGE

public:
    Remote(Device& device) : device_(device) {}
    virtual ~Remote() = default;

    void toggle_power() {
        std::cout << "[" << device_.get_name() << " Remote] Toggle power\n";
        if (device_.is_enabled()) {
            device_.disable();
        } else {
            device_.enable();
        }
    }

    void volume_up() {
        std::cout << "[" << device_.get_name() << " Remote] Volume up\n";
        device_.set_volume(device_.get_volume() + 10);
    }

    void volume_down() {
        std::cout << "[" << device_.get_name() << " Remote] Volume down\n";
        device_.set_volume(device_.get_volume() - 10);
    }

    void channel_up() {
        std::cout << "[" << device_.get_name() << " Remote] Channel up\n";
        device_.set_channel(device_.get_channel() + 1);
    }

    void channel_down() {
        std::cout << "[" << device_.get_name() << " Remote] Channel down\n";
        device_.set_channel(device_.get_channel() - 1);
    }
};
