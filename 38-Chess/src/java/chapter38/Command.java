package chapter38;

/**
 * Command — a reversible action.
 */
public interface Command {
    void execute();
    void undo();
}
