#pragma once
#include "Device.h"
#include <iostream>
#include <algorithm>

class Tv : public Device {
private:
    bool enabled_ = false;
    int volume_ = 30;
    int channel_ = 1;

public:
    bool is_enabled() const override { return enabled_; }

    void enable() override {
        enabled_ = true;
        std::cout << "  TV is ON\n";
    }

    void disable() override {
        enabled_ = false;
        std::cout << "  TV is OFF\n";
    }

    int get_volume() const override { return volume_; }

    void set_volume(int volume) override {
        volume_ = std::clamp(volume, 0, 100);
        std::cout << "  TV volume: " << volume_ << "\n";
    }

    int get_channel() const override { return channel_; }

    void set_channel(int channel) override {
        channel_ = channel;
        std::cout << "  TV channel: " << channel_ << "\n";
    }

    std::string get_name() const override { return "TV"; }
};
