use crate::state::State;
use crate::gumball_machine::GumballMachine;
use crate::no_quarter_state::NoQuarterState;
use crate::sold_state::SoldState;

pub struct HasQuarterState;

impl State for HasQuarterState {
    fn insert_quarter(self: Box<Self>, _machine: &mut GumballMachine) -> Box<dyn State> {
        println!("  You can't insert another quarter");
        self
    }
    fn eject_quarter(self: Box<Self>, _machine: &mut GumballMachine) -> Box<dyn State> {
        println!("  Quarter returned");
        Box::new(NoQuarterState)
    }
    fn turn_crank(self: Box<Self>, _machine: &mut GumballMachine) -> Box<dyn State> {
        println!("  You turned the crank...");
        Box::new(SoldState)
    }
    fn dispense(self: Box<Self>, _machine: &mut GumballMachine) -> Box<dyn State> {
        println!("  No gumball dispensed");
        self
    }
    fn name(&self) -> &str {
        "HasQuarter"
    }
}
