use crate::state::State;
use crate::gumball_machine::GumballMachine;

pub struct SoldOutState;

impl State for SoldOutState {
    fn insert_quarter(self: Box<Self>, _machine: &mut GumballMachine) -> Box<dyn State> {
        println!("  You can't insert a quarter, the machine is sold out");
        self
    }
    fn eject_quarter(self: Box<Self>, _machine: &mut GumballMachine) -> Box<dyn State> {
        println!("  You can't eject, you haven't inserted a quarter yet");
        self
    }
    fn turn_crank(self: Box<Self>, _machine: &mut GumballMachine) -> Box<dyn State> {
        println!("  You turned, but there are no gumballs");
        self
    }
    fn dispense(self: Box<Self>, _machine: &mut GumballMachine) -> Box<dyn State> {
        println!("  No gumball dispensed");
        self
    }
    fn name(&self) -> &str {
        "SoldOut"
    }
}
