package chapter11;

/**
 * Abstraction — high-level remote control operations.
 * Holds a reference to Device (the bridge).
 * This is the other side of the bridge.
 */
public class Remote {
    protected final Device device;  // ← THE BRIDGE

    public Remote(Device device) {
        this.device = device;
    }

    public void togglePower() {
        System.out.println("[" + device.getName() + " Remote] Toggle power");
        if (device.isEnabled()) {
            device.disable();
        } else {
            device.enable();
        }
    }

    public void volumeUp() {
        System.out.println("[" + device.getName() + " Remote] Volume up");
        device.setVolume(device.getVolume() + 10);
    }

    public void volumeDown() {
        System.out.println("[" + device.getName() + " Remote] Volume down");
        device.setVolume(device.getVolume() - 10);
    }

    public void channelUp() {
        System.out.println("[" + device.getName() + " Remote] Channel up");
        device.setChannel(device.getChannel() + 1);
    }

    public void channelDown() {
        System.out.println("[" + device.getName() + " Remote] Channel down");
        device.setChannel(device.getChannel() - 1);
    }
}
