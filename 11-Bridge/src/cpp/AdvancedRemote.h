#pragma once
#include "Remote.h"
#include <iostream>

// Refined Abstraction — advanced remote with extra features
class AdvancedRemote : public Remote {
public:
    AdvancedRemote(Device& device) : Remote(device) {}

    void mute() {
        std::cout << "[" << device_.get_name() << " Advanced Remote] Mute\n";
        device_.set_volume(0);
    }

    void set_channel_direct(int channel) {
        std::cout << "[" << device_.get_name() << " Advanced Remote] Go to channel " << channel << "\n";
        device_.set_channel(channel);
    }

    void print_status() {
        std::cout << "[" << device_.get_name() << " Status] "
                  << "power=" << (device_.is_enabled() ? "ON" : "OFF")
                  << " volume=" << device_.get_volume()
                  << " channel=" << device_.get_channel() << "\n";
    }
};
