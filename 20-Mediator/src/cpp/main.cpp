#include <iostream>
#include "ChatMediator.h"
#include "User.h"
#include "ChatUser.h"
#include "ChatRoom.h"

int main() {
    std::cout << "=== Mediator Pattern Demo (C++) ===\n\n";

    // The mediator
    ChatRoom chat_room;

    // Colleagues — each knows only the chat room, never each other
    ChatUser alice(&chat_room, "Alice");
    ChatUser bob(&chat_room, "Bob");
    ChatUser carol(&chat_room, "Carol");

    chat_room.add_user(&alice);
    chat_room.add_user(&bob);
    chat_room.add_user(&carol);

    // Alice sends — the room delivers to Bob and Carol (not back to Alice)
    alice.send("Hi everyone!");
    std::cout << "\n";

    // Bob replies — same mechanism, zero direct user-to-user references
    bob.send("Hey Alice!");

    std::cout << "\nNo user holds a reference to another user \u2014\n";
    std::cout << "all coordination lives in the ChatRoom mediator.\n";

    return 0;
}
