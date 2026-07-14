use std::rc::Rc;

use crate::user::User;

/// Concrete Mediator — holds the colleagues and owns the coordination logic:
/// broadcast each message to everyone except the sender.
pub struct ChatRoom {
    users: Vec<Rc<User>>,
}

impl ChatRoom {
    pub fn new() -> Self {
        ChatRoom { users: Vec::new() }
    }

    pub fn add_user(&mut self, user: Rc<User>) {
        self.users.push(user);
    }

    pub fn send_message(&self, message: &str, sender_name: &str) {
        for user in &self.users {
            if user.name() != sender_name {
                user.receive(message, sender_name);
            }
        }
    }
}
