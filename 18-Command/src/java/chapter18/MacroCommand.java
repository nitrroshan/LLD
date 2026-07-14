package chapter18;

import java.util.List;

/**
 * Macro Command — a Command that groups other commands (Command + Composite).
 * execute() runs them in order; undo() reverses them in REVERSE order so
 * state unwinds correctly.
 */
public class MacroCommand implements Command {
    private final List<Command> commands;

    public MacroCommand(List<Command> commands) {
        this.commands = commands;
    }

    @Override
    public void execute() {
        for (Command command : commands) {
            command.execute();
        }
    }

    @Override
    public void undo() {
        for (int i = commands.size() - 1; i >= 0; i--) {
            commands.get(i).undo();
        }
    }
}
