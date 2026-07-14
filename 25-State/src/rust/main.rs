mod state;
mod no_quarter_state;
mod has_quarter_state;
mod sold_state;
mod sold_out_state;
mod gumball_machine;

use gumball_machine::GumballMachine;

fn main() {
    println!("=== State Pattern Demo (Rust) ===\n");

    let mut machine = GumballMachine::new(2);
    println!("{}", machine.status());

    println!("\nBuy first gumball:");
    machine.insert_quarter();
    machine.turn_crank();
    println!("{}", machine.status());

    println!("\nBuy second gumball (empties the machine):");
    machine.insert_quarter();
    machine.turn_crank();
    println!("{}", machine.status());

    println!("\nTry to buy when sold out:");
    machine.insert_quarter();
    machine.turn_crank();

    println!("\nSame actions behaved differently in each state —");
    println!("no conditionals, just the current State object.");
}
