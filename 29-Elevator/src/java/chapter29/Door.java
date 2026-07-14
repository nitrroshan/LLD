package chapter29;

/**
 * The car door. Kept minimal; a real system would model timing and sensors.
 */
public class Door {
    private boolean open;

    public void open() {
        open = true;
    }

    public void close() {
        open = false;
    }

    public boolean isOpen() {
        return open;
    }
}
