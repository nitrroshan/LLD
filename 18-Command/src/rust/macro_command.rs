use std::rc::Rc;

use crate::command::Command;

/// Macro Command — groups commands (Command + Composite). undo reverses
/// them in REVERSE order so state unwinds correctly.
pub struct MacroCommand {
    commands: Vec<Rc<dyn Command>>,
}

impl MacroCommand {
    pub fn new(commands: Vec<Rc<dyn Command>>) -> Self {
        MacroCommand { commands }
    }
}

impl Command for MacroCommand {
    fn execute(&self) {
        for command in &self.commands {
            command.execute();
        }
    }

    fn undo(&self) {
        for command in self.commands.iter().rev() {
            command.undo();
        }
    }
}
