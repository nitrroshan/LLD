package chapter06;

public class WindowsMenu implements Menu {
    @Override
    public void render() {
        System.out.println("[Windows Menu] Rendering dropdown menu with separator lines.");
    }

    @Override
    public void select(String item) {
        System.out.println("[Windows Menu] Selected: " + item + " — Windows style.");
    }
}
