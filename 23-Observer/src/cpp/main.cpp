#include <iostream>
#include "WeatherStation.h"
#include "PhoneDisplay.h"
#include "WindowDisplay.h"

int main() {
    std::cout << "=== Observer Pattern Demo (C++) ===\n\n";

    WeatherStation station;

    PhoneDisplay alice_phone("Alice");
    PhoneDisplay bob_phone("Bob");
    WindowDisplay window;

    // Subscribe observers (non-owning pointers)
    station.register_observer(&alice_phone);
    station.register_observer(&bob_phone);
    station.register_observer(&window);

    // One change → everyone is notified automatically
    station.set_temperature(22.5f);

    std::cout << "\n";
    station.set_temperature(28.0f);

    // Unsubscribe at runtime — Bob stops receiving updates
    std::cout << "\nBob unsubscribes...\n";
    station.remove_observer(&bob_phone);

    std::cout << "\n";
    station.set_temperature(19.0f);

    std::cout << "\nThe station never referenced a concrete display \u2014\n";
    std::cout << "it only pushed updates to the Observer list.\n";

    return 0;
}
