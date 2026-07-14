// Subsystem — the video projector.
pub struct Projector;

impl Projector {
    pub fn on(&self) { println!("Projector on"); }
    pub fn off(&self) { println!("Projector off"); }
    pub fn wide_screen_mode(&self) { println!("Projector in widescreen mode (16:9)"); }
}
