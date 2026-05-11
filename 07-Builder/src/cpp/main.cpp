#include <iostream>
#include "HouseBuilder.h"
#include "HouseDirector.h"

int main() {
    std::cout << "=== Builder Pattern Demo ===\n\n";

    // 1. Build a custom house step by step
    House custom_house = HouseBuilder()
            .rooms(4)
            .floors(2)
            .garage()
            .pool()
            .roof_type("tile")
            .build();
    std::cout << "Custom:  " << custom_house.to_string() << "\n";

    // 2. Use the Director for pre-defined configurations
    HouseDirector director;

    House luxury = director.build_luxury_house(HouseBuilder());
    std::cout << "Luxury:  " << luxury.to_string() << "\n";

    House simple = director.build_simple_house(HouseBuilder());
    std::cout << "Simple:  " << simple.to_string() << "\n";

    House family = director.build_family_house(HouseBuilder());
    std::cout << "Family:  " << family.to_string() << "\n";

    // 3. Minimal house — only defaults
    House minimal = HouseBuilder().build();
    std::cout << "Minimal: " << minimal.to_string() << "\n";

    return 0;
}
