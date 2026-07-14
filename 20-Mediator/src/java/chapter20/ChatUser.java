package chapter20;

/**
 * Concrete Colleague — a chat participant. It only implements how it reacts
 * to an incoming message; it has no reference to any other user.
 */
public class ChatUser extends User {
    public ChatUser(ChatMediator mediator, String name) {
        super(mediator, name);
    }

    @Override
    public void receive(String message, String from) {
        System.out.println("    " + name + " received from " + from + ": " + message);
    }
}
