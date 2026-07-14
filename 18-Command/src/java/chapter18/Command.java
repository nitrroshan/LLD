package chapter18;

/**
 * Command — declares execute() and undo(). A command bundles an action
 * together with the receiver that performs it.
 */
public interface Command {
    void execute();
    void undo();
}
