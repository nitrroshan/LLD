package chapter23;

/**
 * Concrete Observer — a phone app that shows the temperature.
 */
public class PhoneDisplay implements Observer {
    private final String name;

    public PhoneDisplay(String name) {
        this.name = name;
    }

    @Override
    public void update(float temperature) {
        System.out.printf("  [Phone %s] It's now %.1f°C%n", name, temperature);
    }
}
