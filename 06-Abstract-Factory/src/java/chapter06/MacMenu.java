package chapter06;

public class MacMenu implements Menu {
    @Override
    public void render() {
        System.out.println("[Mac Menu] Rendering translucent menu with vibrancy effect.");
    }

    @Override
    public void select(String item) {
        System.out.println("[Mac Menu] Selected: " + item + " — macOS style.");
    }
}
