package chapter11;

/**
 * Implementation interface — low-level device operations.
 * This is one side of the bridge.
 */
public interface Device {
    boolean isEnabled();
    void enable();
    void disable();
    int getVolume();
    void setVolume(int volume);
    int getChannel();
    void setChannel(int channel);
    String getName();
}
