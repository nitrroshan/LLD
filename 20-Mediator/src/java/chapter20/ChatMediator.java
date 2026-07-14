package chapter20;

/**
 * Mediator — declares how colleagues communicate. Colleagues talk to this,
 * never to each other directly.
 */
public interface ChatMediator {
    void sendMessage(String message, User sender);
    void addUser(User user);
}
