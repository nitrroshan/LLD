package chapter20;

import java.util.ArrayList;
import java.util.List;

/**
 * Concrete Mediator — holds the colleagues and owns the coordination logic.
 * It broadcasts each message to every user except the sender.
 */
public class ChatRoom implements ChatMediator {
    private final List<User> users = new ArrayList<>();

    @Override
    public void addUser(User user) {
        users.add(user);
    }

    @Override
    public void sendMessage(String message, User sender) {
        for (User user : users) {
            if (user != sender) {
                user.receive(message, sender.getName());
            }
        }
    }
}
