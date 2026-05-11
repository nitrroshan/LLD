package chapter06;

/**
 * Concrete Factory — creates the Mac product family.
 * Every product returned is guaranteed to be Mac-style.
 */
public class MacFactory implements UIFactory {
    @Override
    public Button createButton() { return new MacButton(); }

    @Override
    public Checkbox createCheckbox() { return new MacCheckbox(); }

    @Override
    public Menu createMenu() { return new MacMenu(); }
}
