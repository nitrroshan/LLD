use crate::state::State;
use crate::no_quarter_state::NoQuarterState;
use crate::sold_out_state::SoldOutState;

/// Context — owns the current state (as a boxed trait object) and the shared
/// count. Each action takes the state out, runs it, and stores the returned
/// next state.
pub struct GumballMachine {
    state: Option<Box<dyn State>>,
    count: u32,
}

impl GumballMachine {
    pub fn new(count: u32) -> Self {
        let state: Box<dyn State> = if count > 0 {
            Box::new(NoQuarterState)
        } else {
            Box::new(SoldOutState)
        };
        GumballMachine { state: Some(state), count }
    }

    pub fn insert_quarter(&mut self) {
        let state = self.state.take().unwrap();
        self.state = Some(state.insert_quarter(self));
    }

    pub fn eject_quarter(&mut self) {
        let state = self.state.take().unwrap();
        self.state = Some(state.eject_quarter(self));
    }

    pub fn turn_crank(&mut self) {
        let state = self.state.take().unwrap();
        let state = state.turn_crank(self);
        self.state = Some(state.dispense(self));
    }

    pub fn count(&self) -> u32 {
        self.count
    }

    pub fn release_ball(&mut self) {
        if self.count > 0 {
            println!("  A gumball rolls out...");
            self.count -= 1;
        }
    }

    pub fn status(&self) -> String {
        format!("[state={}, gumballs={}]", self.state.as_ref().unwrap().name(), self.count)
    }
}
