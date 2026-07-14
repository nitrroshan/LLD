// Subsystem — the audio amplifier.
pub struct Amplifier;

impl Amplifier {
    pub fn on(&self) { println!("Amplifier on"); }
    pub fn off(&self) { println!("Amplifier off"); }
    pub fn set_volume(&self, level: i32) { println!("Amplifier volume set to {}", level); }
}
