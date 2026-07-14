use std::rc::Rc;

use crate::command::Command;
use crate::light::Light;

/// Concrete Command — binds "turn off" to a Light; undo turns it on.
pub struct LightOffCommand {
    light: Rc<Light>,
}

impl LightOffCommand {
    pub fn new(light: Rc<Light>) -> Self {
        LightOffCommand { light }
    }
}

impl Command for LightOffCommand {
    fn execute(&self) {
        self.light.off();
    }
    fn undo(&self) {
        self.light.on();
    }
}
