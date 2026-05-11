use crate::device::Device;

pub struct Tv {
    enabled: bool,
    volume: i32,
    channel: i32,
}

impl Tv {
    pub fn new() -> Self {
        Tv { enabled: false, volume: 30, channel: 1 }
    }
}

impl Device for Tv {
    fn is_enabled(&self) -> bool { self.enabled }

    fn enable(&mut self) {
        self.enabled = true;
        println!("  TV is ON");
    }

    fn disable(&mut self) {
        self.enabled = false;
        println!("  TV is OFF");
    }

    fn get_volume(&self) -> i32 { self.volume }

    fn set_volume(&mut self, volume: i32) {
        self.volume = volume.clamp(0, 100);
        println!("  TV volume: {}", self.volume);
    }

    fn get_channel(&self) -> i32 { self.channel }

    fn set_channel(&mut self, channel: i32) {
        self.channel = channel;
        println!("  TV channel: {}", self.channel);
    }

    fn get_name(&self) -> &str { "TV" }
}
