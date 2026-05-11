#include <iostream>
#include "Tv.h"
#include "Radio.h"
#include "Remote.h"
#include "AdvancedRemote.h"

int main() {
    std::cout << "=== Bridge Pattern Demo (C++) ===\n\n";

    // 1. Basic Remote + TV
    std::cout << "--- Basic Remote + TV ---\n";
    Tv tv;
    Remote basic_remote(tv);
    basic_remote.toggle_power();
    basic_remote.volume_up();
    basic_remote.channel_up();
    basic_remote.toggle_power();
    std::cout << "\n";

    // 2. Advanced Remote + Radio
    std::cout << "--- Advanced Remote + Radio ---\n";
    Radio radio;
    AdvancedRemote adv_remote(radio);
    adv_remote.toggle_power();
    adv_remote.set_channel_direct(95);
    adv_remote.volume_up();
    adv_remote.print_status();
    adv_remote.mute();
    adv_remote.print_status();
    std::cout << "\n";

    // 3. Advanced Remote + TV
    std::cout << "--- Advanced Remote + TV ---\n";
    Tv tv2;
    AdvancedRemote adv_tv(tv2);
    adv_tv.toggle_power();
    adv_tv.set_channel_direct(42);
    adv_tv.volume_up();
    adv_tv.volume_up();
    adv_tv.print_status();

    return 0;
}
