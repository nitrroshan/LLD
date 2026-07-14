use std::rc::Rc;

use crate::command::Command;

/// Invoker — holds a command, triggers it, and records history for undo.
/// It knows nothing about receivers, only about `Command`.
pub struct RemoteControl {
    slot: Option<Rc<dyn Command>>,
    history: Vec<Rc<dyn Command>>,
}

impl RemoteControl {
    pub fn new() -> Self {
        RemoteControl { slot: None, history: Vec::new() }
    }

    pub fn set_command(&mut self, command: Rc<dyn Command>) {
        self.slot = Some(command);
    }

    pub fn press_button(&mut self) {
        if let Some(command) = &self.slot {
            command.execute();
            self.history.push(Rc::clone(command));
        }
    }

    pub fn press_undo(&mut self) {
        match self.history.pop() {
            Some(command) => {
                println!("  [undo]");
                command.undo();
            }
            None => println!("  [undo] nothing to undo"),
        }
    }
}
