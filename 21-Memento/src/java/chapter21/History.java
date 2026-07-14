package chapter21;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * Caretaker — stores mementos on a stack for undo. It never reads the state
 * inside a memento; it only holds and returns them.
 */
public class History {
    private final Deque<EditorMemento> mementos = new ArrayDeque<>();

    public void push(EditorMemento memento) {
        mementos.push(memento);
    }

    public EditorMemento pop() {
        return mementos.pop();
    }

    public boolean isEmpty() {
        return mementos.isEmpty();
    }
}
