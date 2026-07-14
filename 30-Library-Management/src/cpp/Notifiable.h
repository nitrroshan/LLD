#pragma once
#include <string>

// Observer — anything the library can push a notification to.
class Notifiable {
public:
    virtual ~Notifiable() = default;
    virtual void on_notify(const std::string& message) = 0;
};
