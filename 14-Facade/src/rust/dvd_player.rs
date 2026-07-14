// Subsystem — the DVD player.
pub struct DvdPlayer;

impl DvdPlayer {
    pub fn on(&self) { println!("DVD player on"); }
    pub fn off(&self) { println!("DVD player off"); }
    pub fn play(&self, movie: &str) { println!("Playing \"{}\"", movie); }
    pub fn stop(&self) { println!("Stopping playback"); }
}
