#pragma once
#include <string>

// Implementation interface — low-level device operations
class Device {
public:
    virtual ~Device() = default;
    virtual bool is_enabled() const = 0;
    virtual void enable() = 0;
    virtual void disable() = 0;
    virtual int get_volume() const = 0;
    virtual void set_volume(int volume) = 0;
    virtual int get_channel() const = 0;
    virtual void set_channel(int channel) = 0;
    virtual std::string get_name() const = 0;
};
