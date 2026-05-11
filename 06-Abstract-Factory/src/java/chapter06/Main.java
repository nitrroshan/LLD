package chapter06;

/**
 * Client code — works entirely through UIFactory + product interfaces.
 * Doesn't know if it's rendering Windows or Mac components.
 *
 * Compile & Run:
 *   cd 06-Abstract-Factory/src/java
 *   javac chapter06/*.java
 *   java chapter06.Main
 */
public class Main {
    // Client method — uses factory without knowing the concrete family
    static void buildUI(UIFactory factory) {
        Button button = factory.createButton();
        Checkbox checkbox = factory.createCheckbox();
        Menu menu = factory.createMenu();

        System.out.println("--- Rendering UI ---");
        button.render();
        checkbox.render();
        menu.render();

        System.out.println("--- Interacting ---");
        button.onClick();
        checkbox.toggle();
        menu.select("File > Save");
    }

    public static void main(String[] args) {
        System.out.println("=== Windows UI ===");
        UIFactory windowsFactory = new WindowsFactory();
        buildUI(windowsFactory);

        System.out.println("\n=== Mac UI ===");
        UIFactory macFactory = new MacFactory();
        buildUI(macFactory);

        // Runtime family selection — imagine reading from config or OS detection
        System.out.println("\n=== Runtime Selection (simulated) ===");
        String os = "mac"; // pretend we detected this
        UIFactory factory = os.equals("windows") ? new WindowsFactory() : new MacFactory();
        buildUI(factory);
    }
}
