mod user;
mod chat_room;

use std::rc::Rc;

use user::User;
use chat_room::ChatRoom;

fn main() {
    println!("=== Mediator Pattern Demo (Rust) ===\n");

    // The mediator
    let mut room = ChatRoom::new();

    // Colleagues — shared via Rc so the room and main both hold them.
    // No user references another user.
    let alice = Rc::new(User::new("Alice"));
    let bob = Rc::new(User::new("Bob"));
    let carol = Rc::new(User::new("Carol"));

    room.add_user(Rc::clone(&alice));
    room.add_user(Rc::clone(&bob));
    room.add_user(Rc::clone(&carol));

    // Alice sends — the room delivers to Bob and Carol (not back to Alice)
    alice.send(&room, "Hi everyone!");
    println!();

    // Bob replies — same mechanism, zero direct user-to-user references
    bob.send(&room, "Hey Alice!");

    println!("\nNo user holds a reference to another user —");
    println!("all coordination lives in the ChatRoom mediator.");
}
