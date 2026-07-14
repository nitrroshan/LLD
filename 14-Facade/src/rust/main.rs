mod projector;
mod screen;
mod amplifier;
mod theater_lights;
mod dvd_player;
mod home_theater_facade;

use projector::Projector;
use screen::Screen;
use amplifier::Amplifier;
use theater_lights::TheaterLights;
use dvd_player::DvdPlayer;
use home_theater_facade::HomeTheaterFacade;

fn main() {
    println!("=== Facade Pattern Demo (Rust) ===\n");

    // Wrap the subsystem components in a facade (the facade owns them)
    let theater = HomeTheaterFacade::new(
        Projector, Screen, Amplifier, TheaterLights, DvdPlayer,
    );

    // Two simple calls instead of orchestrating 8 subsystem steps
    theater.watch_movie("Inception");

    println!();
    theater.end_movie();

    // A separate projector shows the subsystem is usable directly too
    println!("\n--- Direct subsystem access (advanced) ---");
    let projector = Projector;
    projector.on();
    projector.wide_screen_mode();
    projector.off();
}
