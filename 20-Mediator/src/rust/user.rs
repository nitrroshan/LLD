use crate::chat_room::ChatRoom;

/// Colleague. In GC languages a User stores a reference to the mediator.
/// In Rust, storing mutual references (room -> users -> room) creates a
/// reference cycle that needs `Rc<RefCell<>>` + `Weak`. For clarity we
/// instead PASS the mediator into `send` — the colleague still talks only
/// through the mediator, never to another user directly.
pub struct User {
    name: String,
}

impl User {
    pub fn new(name: &str) -> Self {
        User { name: name.to_string() }
    }

    pub fn name(&self) -> &str {
        &self.name
    }

    /// Send a message — routed through the mediator, not to peers directly.
    pub fn send(&self, room: &ChatRoom, message: &str) {
        println!("{} sends: {}", self.name, message);
        room.send_message(message, &self.name);
    }

    pub fn receive(&self, message: &str, from: &str) {
        println!("    {} received from {}: {}", self.name, from, message);
    }
}
