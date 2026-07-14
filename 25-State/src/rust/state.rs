use crate::gumball_machine::GumballMachine;

/// State — each action CONSUMES the current state (`self: Box<Self>`) and
/// returns the next state. This ownership-based form is the idiomatic Rust
/// state machine: it avoids a mutable context<->state reference cycle.
pub trait State {
    fn insert_quarter(self: Box<Self>, machine: &mut GumballMachine) -> Box<dyn State>;
    fn eject_quarter(self: Box<Self>, machine: &mut GumballMachine) -> Box<dyn State>;
    fn turn_crank(self: Box<Self>, machine: &mut GumballMachine) -> Box<dyn State>;
    fn dispense(self: Box<Self>, machine: &mut GumballMachine) -> Box<dyn State>;
    fn name(&self) -> &str;
}
