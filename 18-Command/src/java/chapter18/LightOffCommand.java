package chapter18;

/**
 * Concrete Command — binds the "turn off" action to a Light receiver.
 * undo() reverses it by turning the light on.
 */
public class LightOffCommand implements Command {
    private final Light light;

    public LightOffCommand(Light light) {
        this.light = light;
    }

    @Override
    public void execute() {
        light.off();
    }

    @Override
    public void undo() {
        light.on();
    }
}
