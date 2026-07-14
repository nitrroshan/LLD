package chapter16;

/**
 * Subject — the common interface shared by the real object and the proxy.
 * Clients depend only on this, so a proxy is interchangeable with the real image.
 */
public interface Image {
    void display();
}
