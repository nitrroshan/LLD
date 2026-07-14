mod command;
mod light;
mod light_on_command;
mod light_off_command;
mod macro_command;
mod remote_control;

use std::rc::Rc;

use command::Command;
use light::Light;
use light_on_command::LightOnCommand;
use light_off_command::LightOffCommand;
use macro_command::MacroCommand;
use remote_control::RemoteControl;

fn main() {
    println!("=== Command Pattern Demo (Rust) ===\n");

    // Receivers (shared via Rc so multiple commands can target the same light)
    let living_room = Rc::new(Light::new("Living Room"));
    let kitchen = Rc::new(Light::new("Kitchen"));

    // Concrete commands binding actions to receivers
    let living_room_on: Rc<dyn Command> = Rc::new(LightOnCommand::new(Rc::clone(&living_room)));
    let living_room_off: Rc<dyn Command> = Rc::new(LightOffCommand::new(Rc::clone(&living_room)));
    let kitchen_on: Rc<dyn Command> = Rc::new(LightOnCommand::new(Rc::clone(&kitchen)));

    let mut remote = RemoteControl::new();

    println!("Turn living room light on:");
    remote.set_command(Rc::clone(&living_room_on));
    remote.press_button();

    println!("\nTurn it off:");
    remote.set_command(Rc::clone(&living_room_off));
    remote.press_button();

    println!("\nUndo (should turn back on):");
    remote.press_undo();

    println!("\nUndo again (should turn off):");
    remote.press_undo();

    // Macro command — "party mode"
    println!("\n--- Macro Command: Party Mode ---");
    let party_mode: Rc<dyn Command> =
        Rc::new(MacroCommand::new(vec![Rc::clone(&living_room_on), Rc::clone(&kitchen_on)]));
    remote.set_command(party_mode);
    remote.press_button();

    println!("\nUndo party mode (reverses both, in reverse order):");
    remote.press_undo();
}
