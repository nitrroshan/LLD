package chapter18;

/**
 * Concrete Command — binds the "turn on" action to a Light receiver.
 * undo() reverses it by turning the light off.
 */
public class LightOnCommand implements Command {
    private final Light light;

    public LightOnCommand(Light light) {
        this.light = light;
    }

    @Override
    public void execute() {
        light.on();
    }

    @Override
    public void undo() {
        light.off();
    }
}
