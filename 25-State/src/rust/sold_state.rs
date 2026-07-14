use crate::state::State;
use crate::gumball_machine::GumballMachine;
use crate::no_quarter_state::NoQuarterState;
use crate::sold_out_state::SoldOutState;

pub struct SoldState;

impl State for SoldState {
    fn insert_quarter(self: Box<Self>, _machine: &mut GumballMachine) -> Box<dyn State> {
        println!("  Please wait, we're already giving you a gumball");
        self
    }
    fn eject_quarter(self: Box<Self>, _machine: &mut GumballMachine) -> Box<dyn State> {
        println!("  Sorry, you already turned the crank");
        self
    }
    fn turn_crank(self: Box<Self>, _machine: &mut GumballMachine) -> Box<dyn State> {
        println!("  Turning twice doesn't get you another gumball");
        self
    }
    fn dispense(self: Box<Self>, machine: &mut GumballMachine) -> Box<dyn State> {
        machine.release_ball();
        if machine.count() > 0 {
            Box::new(NoQuarterState)
        } else {
            println!("  Oops, out of gumballs!");
            Box::new(SoldOutState)
        }
    }
    fn name(&self) -> &str {
        "Sold"
    }
}
