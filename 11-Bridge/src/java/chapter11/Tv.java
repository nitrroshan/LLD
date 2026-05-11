package chapter11;

public class Tv implements Device {
    private boolean enabled = false;
    private int volume = 30;
    private int channel = 1;

    @Override
    public boolean isEnabled() { return enabled; }

    @Override
    public void enable() {
        enabled = true;
        System.out.println("  TV is ON");
    }

    @Override
    public void disable() {
        enabled = false;
        System.out.println("  TV is OFF");
    }

    @Override
    public int getVolume() { return volume; }

    @Override
    public void setVolume(int volume) {
        this.volume = Math.max(0, Math.min(100, volume));
        System.out.println("  TV volume: " + this.volume);
    }

    @Override
    public int getChannel() { return channel; }

    @Override
    public void setChannel(int channel) {
        this.channel = channel;
        System.out.println("  TV channel: " + this.channel);
    }

    @Override
    public String getName() { return "TV"; }
}
