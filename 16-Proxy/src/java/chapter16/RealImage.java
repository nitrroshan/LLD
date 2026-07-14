package chapter16;

/**
 * RealSubject — the expensive object. Loading from disk is simulated as
 * costly work that happens in the constructor.
 */
public class RealImage implements Image {
    private final String filename;

    public RealImage(String filename) {
        this.filename = filename;
        loadFromDisk();
    }

    private void loadFromDisk() {
        System.out.println("  [RealImage] Loading " + filename + " from disk (expensive)...");
    }

    @Override
    public void display() {
        System.out.println("  [RealImage] Displaying " + filename);
    }
}
