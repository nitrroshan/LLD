package chapter23;

/**
 * Observer — the update interface all subscribers implement. Push model:
 * the new temperature is passed in.
 */
public interface Observer {
    void update(float temperature);
}
