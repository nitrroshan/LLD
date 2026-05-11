package chapter06;

public class WindowsCheckbox implements Checkbox {
    @Override
    public void render() {
        System.out.println("[Windows Checkbox] Rendering square checkbox with checkmark.");
    }

    @Override
    public void toggle() {
        System.out.println("[Windows Checkbox] Toggled — Windows style.");
    }
}
