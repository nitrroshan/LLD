package chapter23;

/**
 * Concrete Observer — a window dashboard that reacts to temperature.
 */
public class WindowDisplay implements Observer {
    @Override
    public void update(float temperature) {
        String advice = temperature > 25 ? "open the windows" : "keep them closed";
        System.out.printf("  [Window] %.1f°C — %s%n", temperature, advice);
    }
}
