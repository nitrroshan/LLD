#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include "Subject.h"
#include "Observer.h"

// Concrete Subject — holds the temperature and pushes updates to every
// registered observer. Stores non-owning Observer pointers.
class WeatherStation : public Subject {
    std::vector<Observer*> observers_;
    float temperature_ = 0;

public:
    void set_temperature(float temperature) {
        temperature_ = temperature;
        std::cout << "WeatherStation: temperature -> " << temperature << " C\n";
        notify_observers();
    }

    void register_observer(Observer* observer) override {
        observers_.push_back(observer);
    }

    void remove_observer(Observer* observer) override {
        observers_.erase(std::remove(observers_.begin(), observers_.end(), observer),
                         observers_.end());
    }

    void notify_observers() override {
        // Copy so an observer may unsubscribe during notification.
        std::vector<Observer*> snapshot = observers_;
        for (Observer* observer : snapshot) {
            observer->update(temperature_);
        }
    }
};
