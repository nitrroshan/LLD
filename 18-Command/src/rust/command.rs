/// Command — bundles an action with its receiver. `execute` performs it,
/// `undo` reverses it. Takes `&self`; receivers needing mutation would use
/// `Rc<RefCell<Receiver>>` (see the notes).
pub trait Command {
    fn execute(&self);
    fn undo(&self);
}
