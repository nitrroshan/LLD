use crate::state::State;
use crate::gumball_machine::GumballMachine;
use crate::has_quarter_state::HasQuarterState;

pub struct NoQuarterState;

impl State for NoQuarterState {
    fn insert_quarter(self: Box<Self>, _machine: &mut GumballMachine) -> Box<dyn State> {
        println!("  You inserted a quarter");
        Box::new(HasQuarterState) // transition
    }
    fn eject_quarter(self: Box<Self>, _machine: &mut GumballMachine) -> Box<dyn State> {
        println!("  You haven't inserted a quarter");
        self
    }
    fn turn_crank(self: Box<Self>, _machine: &mut GumballMachine) -> Box<dyn State> {
        println!("  You turned, but there's no quarter");
        self
    }
    fn dispense(self: Box<Self>, _machine: &mut GumballMachine) -> Box<dyn State> {
        println!("  You need to pay first");
        self
    }
    fn name(&self) -> &str {
        "NoQuarter"
    }
}
