#pragma once

// Coin denominations in cents. Penny has no handler in the chain -> rejected.
enum class Coin { Penny, Nickel, Dime, Quarter, Dollar };

inline int value_of(Coin c) {
    switch (c) {
        case Coin::Penny:   return 1;
        case Coin::Nickel:  return 5;
        case Coin::Dime:    return 10;
        case Coin::Quarter: return 25;
        case Coin::Dollar:  return 100;
    }
    return 0;
}

inline const char* to_string(Coin c) {
    switch (c) {
        case Coin::Penny:   return "PENNY";
        case Coin::Nickel:  return "NICKEL";
        case Coin::Dime:    return "DIME";
        case Coin::Quarter: return "QUARTER";
        case Coin::Dollar:  return "DOLLAR";
    }
    return "?";
}
