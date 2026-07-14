package chapter14;

/**
 * Subsystem class — knows how to project video. Unaware of the facade.
 */
public class Projector {
    public void on() {
        System.out.println("Projector on");
    }

    public void off() {
        System.out.println("Projector off");
    }

    public void wideScreenMode() {
        System.out.println("Projector in widescreen mode (16:9)");
    }
}
