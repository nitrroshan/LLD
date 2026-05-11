use crate::device::Device;

/// Abstraction — high-level remote control operations.
/// Holds a mutable reference to a Device (the bridge).
pub struct Remote<'a> {
    device: &'a mut dyn Device,
}

impl<'a> Remote<'a> {
    pub fn new(device: &'a mut dyn Device) -> Self {
        Remote { device }
    }

    pub fn toggle_power(&mut self) {
        println!("[{} Remote] Toggle power", self.device.get_name());
        if self.device.is_enabled() {
            self.device.disable();
        } else {
            self.device.enable();
        }
    }

    pub fn volume_up(&mut self) {
        println!("[{} Remote] Volume up", self.device.get_name());
        let vol = self.device.get_volume() + 10;
        self.device.set_volume(vol);
    }

    pub fn volume_down(&mut self) {
        println!("[{} Remote] Volume down", self.device.get_name());
        let vol = self.device.get_volume() - 10;
        self.device.set_volume(vol);
    }

    pub fn channel_up(&mut self) {
        println!("[{} Remote] Channel up", self.device.get_name());
        let ch = self.device.get_channel() + 1;
        self.device.set_channel(ch);
    }
}
