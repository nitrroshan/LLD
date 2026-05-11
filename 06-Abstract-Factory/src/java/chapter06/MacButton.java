package chapter06;

public class MacButton implements Button {
    @Override
    public void render() {
        System.out.println("[Mac Button] Rendering rounded Aqua-style button.");
    }

    @Override
    public void onClick() {
        System.out.println("[Mac Button] Click — executing macOS command.");
    }
}
