use crate::device::Device;

pub struct Radio {
    enabled: bool,
    volume: i32,
    channel: i32,
}

impl Radio {
    pub fn new() -> Self {
        Radio { enabled: false, volume: 20, channel: 88 }
    }
}

impl Device for Radio {
    fn is_enabled(&self) -> bool { self.enabled }

    fn enable(&mut self) {
        self.enabled = true;
        println!("  Radio is ON");
    }

    fn disable(&mut self) {
        self.enabled = false;
        println!("  Radio is OFF");
    }

    fn get_volume(&self) -> i32 { self.volume }

    fn set_volume(&mut self, volume: i32) {
        self.volume = volume.clamp(0, 100);
        println!("  Radio volume: {}", self.volume);
    }

    fn get_channel(&self) -> i32 { self.channel }

    fn set_channel(&mut self, channel: i32) {
        self.channel = channel;
        println!("  Radio station: {} FM", self.channel);
    }

    fn get_name(&self) -> &str { "Radio" }
}
