package chapter06;

public class WindowsButton implements Button {
    @Override
    public void render() {
        System.out.println("[Windows Button] Rendering flat-style button with sharp corners.");
    }

    @Override
    public void onClick() {
        System.out.println("[Windows Button] Click — executing Windows command.");
    }
}
