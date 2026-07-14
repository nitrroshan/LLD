package chapter20;

/**
 * Colleague — knows ONLY the mediator. It sends through the mediator and
 * reacts to messages the mediator delivers.
 */
public abstract class User {
    protected final ChatMediator mediator;
    protected final String name;

    protected User(ChatMediator mediator, String name) {
        this.mediator = mediator;
        this.name = name;
    }

    public String getName() {
        return name;
    }

    /** Send a message — routed through the mediator, not to peers directly. */
    public void send(String message) {
        System.out.println(name + " sends: " + message);
        mediator.sendMessage(message, this);
    }

    public abstract void receive(String message, String from);
}
