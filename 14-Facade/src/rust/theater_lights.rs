// Subsystem — the dimmable theater lights.
pub struct TheaterLights;

impl TheaterLights {
    pub fn on(&self) { println!("Theater lights on"); }
    pub fn dim(&self, level: i32) { println!("Theater lights dimming to {}%", level); }
}
