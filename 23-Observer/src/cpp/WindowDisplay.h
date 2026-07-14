#pragma once
#include <iostream>
#include "Observer.h"

// Concrete Observer — a window dashboard that reacts to temperature.
class WindowDisplay : public Observer {
public:
    void update(float temperature) override {
        const char* advice = temperature > 25 ? "open the windows" : "keep them closed";
        std::cout << "  [Window] " << temperature << " C \u2014 " << advice << "\n";
    }
};
