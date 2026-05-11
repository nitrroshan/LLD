package chapter06;

/**
 * Concrete Factory — creates the Windows product family.
 * Every product returned is guaranteed to be Windows-style.
 */
public class WindowsFactory implements UIFactory {
    @Override
    public Button createButton() { return new WindowsButton(); }

    @Override
    public Checkbox createCheckbox() { return new WindowsCheckbox(); }

    @Override
    public Menu createMenu() { return new WindowsMenu(); }
}
