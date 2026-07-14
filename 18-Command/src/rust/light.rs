/// Receiver — knows how to perform the real work.
pub struct Light {
    location: String,
}

impl Light {
    pub fn new(location: &str) -> Self {
        Light { location: location.to_string() }
    }

    pub fn on(&self) {
        println!("  {} light is ON", self.location);
    }

    pub fn off(&self) {
        println!("  {} light is OFF", self.location);
    }
}
