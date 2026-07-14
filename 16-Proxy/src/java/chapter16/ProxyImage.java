package chapter16;

/**
 * Virtual Proxy — same interface as RealImage, but defers the expensive
 * disk load until display() is called for the FIRST time (lazy loading).
 */
public class ProxyImage implements Image {
    private final String filename;
    private RealImage realImage;   // not created until first use

    public ProxyImage(String filename) {
        this.filename = filename;
        System.out.println("  [ProxyImage] Created for " + filename + " (nothing loaded yet)");
    }

    @Override
    public void display() {
        if (realImage == null) {
            realImage = new RealImage(filename);   // create on first display only
        }
        realImage.display();
    }
}
