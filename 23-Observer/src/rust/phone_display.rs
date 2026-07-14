use crate::observer::Observer;

/// Concrete Observer — a phone app that shows the temperature.
pub struct PhoneDisplay {
    name: String,
}

impl PhoneDisplay {
    pub fn new(name: &str) -> Self {
        PhoneDisplay { name: name.to_string() }
    }
}

impl Observer for PhoneDisplay {
    fn update(&self, temperature: f64) {
        println!("  [Phone {}] It's now {:.1}°C", self.name, temperature);
    }
}
