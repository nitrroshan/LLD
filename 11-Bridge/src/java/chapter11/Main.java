package chapter11;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Bridge Pattern Demo ===\n");

        // 1. Basic Remote + TV
        System.out.println("--- Basic Remote + TV ---");
        Device tv = new Tv();
        Remote basicRemote = new Remote(tv);
        basicRemote.togglePower();    // TV ON
        basicRemote.volumeUp();       // 40
        basicRemote.channelUp();      // 2
        basicRemote.togglePower();    // TV OFF
        System.out.println();

        // 2. Advanced Remote + Radio
        System.out.println("--- Advanced Remote + Radio ---");
        Device radio = new Radio();
        AdvancedRemote advancedRemote = new AdvancedRemote(radio);
        advancedRemote.togglePower();       // Radio ON
        advancedRemote.setChannelDirect(95);// Station 95 FM
        advancedRemote.volumeUp();          // 30
        advancedRemote.printStatus();
        advancedRemote.mute();              // volume 0
        advancedRemote.printStatus();
        System.out.println();

        // 3. Advanced Remote + TV — same remote type, different device
        System.out.println("--- Advanced Remote + TV ---");
        Device tv2 = new Tv();
        AdvancedRemote advTv = new AdvancedRemote(tv2);
        advTv.togglePower();
        advTv.setChannelDirect(42);
        advTv.volumeUp();
        advTv.volumeUp();
        advTv.printStatus();
        System.out.println();

        // 4. Demonstrate independence — 2 remotes × 2 devices = 4 combos, only 4 classes total
        System.out.println("--- All Combinations (2 remotes × 2 devices = 4 classes, not 4 subclasses) ---");
        System.out.println("BasicRemote + TV:       ✓ (shown above)");
        System.out.println("BasicRemote + Radio:    ✓ new Remote(new Radio())");
        System.out.println("AdvancedRemote + TV:    ✓ (shown above)");
        System.out.println("AdvancedRemote + Radio: ✓ (shown above)");
        System.out.println("Adding a Stereo device: just 1 new class, all remotes work with it!");
    }
}
