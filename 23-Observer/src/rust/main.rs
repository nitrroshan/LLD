mod observer;
mod weather_station;
mod phone_display;
mod window_display;

use std::rc::Rc;

use observer::Observer;
use weather_station::WeatherStation;
use phone_display::PhoneDisplay;
use window_display::WindowDisplay;

fn main() {
    println!("=== Observer Pattern Demo (Rust) ===\n");

    let mut station = WeatherStation::new();

    let alice_phone: Rc<dyn Observer> = Rc::new(PhoneDisplay::new("Alice"));
    let bob_phone: Rc<dyn Observer> = Rc::new(PhoneDisplay::new("Bob"));
    let window: Rc<dyn Observer> = Rc::new(WindowDisplay);

    // Subscribe observers
    station.register_observer(Rc::clone(&alice_phone));
    station.register_observer(Rc::clone(&bob_phone));
    station.register_observer(Rc::clone(&window));

    // One change → everyone is notified automatically
    station.set_temperature(22.5);

    println!();
    station.set_temperature(28.0);

    // Unsubscribe at runtime — Bob stops receiving updates
    println!("\nBob unsubscribes...");
    station.remove_observer(&bob_phone);

    println!();
    station.set_temperature(19.0);

    println!("\nThe station never referenced a concrete display —");
    println!("it only pushed updates to the Observer list.");
}
