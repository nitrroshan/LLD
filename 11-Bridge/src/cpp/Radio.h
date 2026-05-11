#pragma once
#include "Device.h"
#include <iostream>
#include <algorithm>

class Radio : public Device {
private:
    bool enabled_ = false;
    int volume_ = 20;
    int channel_ = 88;

public:
    bool is_enabled() const override { return enabled_; }

    void enable() override {
        enabled_ = true;
        std::cout << "  Radio is ON\n";
    }

    void disable() override {
        enabled_ = false;
        std::cout << "  Radio is OFF\n";
    }

    int get_volume() const override { return volume_; }

    void set_volume(int volume) override {
        volume_ = std::clamp(volume, 0, 100);
        std::cout << "  Radio volume: " << volume_ << "\n";
    }

    int get_channel() const override { return channel_; }

    void set_channel(int channel) override {
        channel_ = channel;
        std::cout << "  Radio station: " << channel_ << " FM\n";
    }

    std::string get_name() const override { return "Radio"; }
};
