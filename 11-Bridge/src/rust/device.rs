/// Implementation interface — low-level device operations.
pub trait Device {
    fn is_enabled(&self) -> bool;
    fn enable(&mut self);
    fn disable(&mut self);
    fn get_volume(&self) -> i32;
    fn set_volume(&mut self, volume: i32);
    fn get_channel(&self) -> i32;
    fn set_channel(&mut self, channel: i32);
    fn get_name(&self) -> &str;
}
