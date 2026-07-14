package chapter14;

/**
 * Subsystem class — the dimmable theater lights.
 */
public class TheaterLights {
    public void on() {
        System.out.println("Theater lights on");
    }

    public void dim(int level) {
        System.out.println("Theater lights dimming to " + level + "%");
    }
}
