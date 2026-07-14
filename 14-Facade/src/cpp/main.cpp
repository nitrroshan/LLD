#include <iostream>
#include "Projector.h"
#include "Screen.h"
#include "Amplifier.h"
#include "TheaterLights.h"
#include "DvdPlayer.h"
#include "HomeTheaterFacade.h"

int main() {
    std::cout << "=== Facade Pattern Demo (C++) ===\n\n";

    // Build the subsystem components
    Projector projector;
    Screen screen;
    Amplifier amplifier;
    TheaterLights lights;
    DvdPlayer dvd_player;

    // Wrap them in a facade
    HomeTheaterFacade theater(projector, screen, amplifier, lights, dvd_player);

    // Two simple calls instead of orchestrating 8 subsystem steps
    theater.watch_movie("Inception");

    std::cout << "\n";
    theater.end_movie();

    // The subsystem is still accessible for advanced use
    std::cout << "\n--- Direct subsystem access (advanced) ---\n";
    projector.on();
    projector.wide_screen_mode();
    projector.off();

    return 0;
}
