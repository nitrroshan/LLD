use std::rc::Rc;

use crate::command::Command;
use crate::light::Light;

/// Concrete Command — binds "turn on" to a Light; undo turns it off.
pub struct LightOnCommand {
    light: Rc<Light>,
}

impl LightOnCommand {
    pub fn new(light: Rc<Light>) -> Self {
        LightOnCommand { light }
    }
}

impl Command for LightOnCommand {
    fn execute(&self) {
        self.light.on();
    }
    fn undo(&self) {
        self.light.off();
    }
}
