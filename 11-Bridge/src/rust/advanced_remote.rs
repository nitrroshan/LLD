use crate::device::Device;

/// Refined Abstraction — advanced remote with extra features.
pub struct AdvancedRemote<'a> {
    device: &'a mut dyn Device,
}

impl<'a> AdvancedRemote<'a> {
    pub fn new(device: &'a mut dyn Device) -> Self {
        AdvancedRemote { device }
    }

    pub fn toggle_power(&mut self) {
        println!("[{} Advanced Remote] Toggle power", self.device.get_name());
        if self.device.is_enabled() {
            self.device.disable();
        } else {
            self.device.enable();
        }
    }

    pub fn volume_up(&mut self) {
        println!("[{} Advanced Remote] Volume up", self.device.get_name());
        let vol = self.device.get_volume() + 10;
        self.device.set_volume(vol);
    }

    pub fn mute(&mut self) {
        println!("[{} Advanced Remote] Mute", self.device.get_name());
        self.device.set_volume(0);
    }

    pub fn set_channel_direct(&mut self, channel: i32) {
        println!("[{} Advanced Remote] Go to channel {}", self.device.get_name(), channel);
        self.device.set_channel(channel);
    }

    pub fn print_status(&self) {
        println!("[{} Status] power={} volume={} channel={}",
                 self.device.get_name(),
                 if self.device.is_enabled() { "ON" } else { "OFF" },
                 self.device.get_volume(),
                 self.device.get_channel());
    }
}
