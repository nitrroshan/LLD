package chapter06;

public class MacCheckbox implements Checkbox {
    @Override
    public void render() {
        System.out.println("[Mac Checkbox] Rendering rounded checkbox with smooth animation.");
    }

    @Override
    public void toggle() {
        System.out.println("[Mac Checkbox] Toggled — macOS style.");
    }
}
