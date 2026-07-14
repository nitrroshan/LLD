package chapter14;

/**
 * Subsystem class — the DVD player.
 */
public class DvdPlayer {
    public void on() {
        System.out.println("DVD player on");
    }

    public void off() {
        System.out.println("DVD player off");
    }

    public void play(String movie) {
        System.out.println("Playing \"" + movie + "\"");
    }

    public void stop() {
        System.out.println("Stopping playback");
    }
}
