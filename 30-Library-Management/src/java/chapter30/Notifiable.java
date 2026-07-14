package chapter30;

/**
 * Observer — anything the library can push a notification to.
 */
public interface Notifiable {
    void onNotify(String message);
}
