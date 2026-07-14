use crate::projector::Projector;
use crate::screen::Screen;
use crate::amplifier::Amplifier;
use crate::theater_lights::TheaterLights;
use crate::dvd_player::DvdPlayer;

/// Facade — owns the subsystem components and sequences their calls.
pub struct HomeTheaterFacade {
    projector: Projector,
    screen: Screen,
    amplifier: Amplifier,
    lights: TheaterLights,
    dvd_player: DvdPlayer,
}

impl HomeTheaterFacade {
    pub fn new(projector: Projector, screen: Screen, amplifier: Amplifier,
               lights: TheaterLights, dvd_player: DvdPlayer) -> Self {
        HomeTheaterFacade { projector, screen, amplifier, lights, dvd_player }
    }

    pub fn watch_movie(&self, movie: &str) {
        println!("Get ready to watch a movie...");
        self.lights.dim(10);
        self.screen.down();
        self.projector.on();
        self.projector.wide_screen_mode();
        self.amplifier.on();
        self.amplifier.set_volume(8);
        self.dvd_player.on();
        self.dvd_player.play(movie);
    }

    pub fn end_movie(&self) {
        println!("Shutting movie theater down...");
        self.dvd_player.stop();
        self.dvd_player.off();
        self.amplifier.off();
        self.projector.off();
        self.screen.up();
        self.lights.on();
    }
}
