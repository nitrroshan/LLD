package chapter18;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * Invoker — holds a command in its slot, triggers it, and records a history
 * stack so the last action can be undone. Knows nothing about receivers.
 */
public class RemoteControl {
    private Command slot;
    private final Deque<Command> history = new ArrayDeque<>();

    public void setCommand(Command command) {
        this.slot = command;
    }

    public void pressButton() {
        if (slot != null) {
            slot.execute();
            history.push(slot);
        }
    }

    public void pressUndo() {
        if (!history.isEmpty()) {
            System.out.println("  [undo]");
            history.pop().undo();
        } else {
            System.out.println("  [undo] nothing to undo");
        }
    }
}
