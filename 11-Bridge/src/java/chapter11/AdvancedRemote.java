package chapter11;

/**
 * Refined Abstraction — advanced remote with extra features.
 * Works with ANY Device — TV, Radio, or any future device.
 */
public class AdvancedRemote extends Remote {

    public AdvancedRemote(Device device) {
        super(device);
    }

    public void mute() {
        System.out.println("[" + device.getName() + " Advanced Remote] Mute");
        device.setVolume(0);
    }

    public void setChannelDirect(int channel) {
        System.out.println("[" + device.getName() + " Advanced Remote] Go to channel " + channel);
        device.setChannel(channel);
    }

    public void printStatus() {
        System.out.println("[" + device.getName() + " Status] " +
                "power=" + (device.isEnabled() ? "ON" : "OFF") +
                " volume=" + device.getVolume() +
                " channel=" + device.getChannel());
    }
}
