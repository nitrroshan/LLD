#pragma once
#include <string>
#include "Projector.h"
#include "Screen.h"
#include "Amplifier.h"
#include "TheaterLights.h"
#include "DvdPlayer.h"

// Facade — simple interface over the home theater subsystem.
class HomeTheaterFacade {
    Projector& projector_;
    Screen& screen_;
    Amplifier& amplifier_;
    TheaterLights& lights_;
    DvdPlayer& dvd_player_;

public:
    HomeTheaterFacade(Projector& projector, Screen& screen, Amplifier& amplifier,
                      TheaterLights& lights, DvdPlayer& dvd_player)
        : projector_(projector), screen_(screen), amplifier_(amplifier),
          lights_(lights), dvd_player_(dvd_player) {}

    void watch_movie(const std::string& movie) {
        std::cout << "Get ready to watch a movie...\n";
        lights_.dim(10);
        screen_.down();
        projector_.on();
        projector_.wide_screen_mode();
        amplifier_.on();
        amplifier_.set_volume(8);
        dvd_player_.on();
        dvd_player_.play(movie);
    }

    void end_movie() {
        std::cout << "Shutting movie theater down...\n";
        dvd_player_.stop();
        dvd_player_.off();
        amplifier_.off();
        projector_.off();
        screen_.up();
        lights_.on();
    }
};
