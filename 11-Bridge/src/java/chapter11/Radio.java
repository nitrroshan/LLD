package chapter11;

public class Radio implements Device {
    private boolean enabled = false;
    private int volume = 20;
    private int channel = 88;

    @Override
    public boolean isEnabled() { return enabled; }

    @Override
    public void enable() {
        enabled = true;
        System.out.println("  Radio is ON");
    }

    @Override
    public void disable() {
        enabled = false;
        System.out.println("  Radio is OFF");
    }

    @Override
    public int getVolume() { return volume; }

    @Override
    public void setVolume(int volume) {
        this.volume = Math.max(0, Math.min(100, volume));
        System.out.println("  Radio volume: " + this.volume);
    }

    @Override
    public int getChannel() { return channel; }

    @Override
    public void setChannel(int channel) {
        this.channel = channel;
        System.out.println("  Radio station: " + this.channel + " FM");
    }

    @Override
    public String getName() { return "Radio"; }
}
