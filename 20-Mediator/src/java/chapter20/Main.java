package chapter20;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Mediator Pattern Demo ===\n");

        // The mediator
        ChatMediator chatRoom = new ChatRoom();

        // Colleagues — each knows only the chat room, never each other
        User alice = new ChatUser(chatRoom, "Alice");
        User bob = new ChatUser(chatRoom, "Bob");
        User carol = new ChatUser(chatRoom, "Carol");

        chatRoom.addUser(alice);
        chatRoom.addUser(bob);
        chatRoom.addUser(carol);

        // Alice sends — the room delivers to Bob and Carol (not back to Alice)
        alice.send("Hi everyone!");
        System.out.println();

        // Bob replies — same mechanism, zero direct user-to-user references
        bob.send("Hey Alice!");

        System.out.println("\nNo user holds a reference to another user —");
        System.out.println("all coordination lives in the ChatRoom mediator.");
    }
}
