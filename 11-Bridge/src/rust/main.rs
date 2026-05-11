mod device;
mod tv;
mod radio;
mod remote;
mod advanced_remote;

use tv::Tv;
use radio::Radio;
use remote::Remote;
use advanced_remote::AdvancedRemote;

fn main() {
    println!("=== Bridge Pattern Demo (Rust) ===\n");

    // 1. Basic Remote + TV
    println!("--- Basic Remote + TV ---");
    {
        let mut tv = Tv::new();
        let mut basic = Remote::new(&mut tv);
        basic.toggle_power();
        basic.volume_up();
        basic.channel_up();
        basic.toggle_power();
    }
    println!();

    // 2. Advanced Remote + Radio
    println!("--- Advanced Remote + Radio ---");
    {
        let mut radio = Radio::new();
        let mut adv = AdvancedRemote::new(&mut radio);
        adv.toggle_power();
        adv.set_channel_direct(95);
        adv.volume_up();
        adv.print_status();
        adv.mute();
        adv.print_status();
    }
    println!();

    // 3. Advanced Remote + TV
    println!("--- Advanced Remote + TV ---");
    {
        let mut tv2 = Tv::new();
        let mut adv_tv = AdvancedRemote::new(&mut tv2);
        adv_tv.toggle_power();
        adv_tv.set_channel_direct(42);
        adv_tv.volume_up();
        adv_tv.volume_up();
        adv_tv.print_status();
    }
}
