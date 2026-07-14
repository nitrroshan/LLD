#include <iostream>
#include <array>
#include "Forest.h"

int main() {
    std::cout << "=== Flyweight Pattern Demo (C++) ===\n\n";

    Forest forest;

    // Plant 1,000,000 trees, but only 3 distinct types
    std::cout << "Planting 1,000,000 trees...\n";
    std::array<std::array<std::string, 3>, 3> species = {{
        {"Oak", "Green", "oak.png"},
        {"Pine", "DarkGreen", "pine.png"},
        {"Cherry", "Pink", "cherry.png"},
    }};

    for (int i = 0; i < 1000000; ++i) {
        const auto& s = species[i % species.size()];
        forest.plant_tree(i % 800, i % 600, s[0], s[1], s[2]);
    }

    std::cout << "\nResult:\n";
    std::cout << "  Trees planted:        " << forest.tree_count() << "\n";
    std::cout << "  Distinct TreeTypes:   " << forest.distinct_type_count() << "\n";
    std::cout << "  Memory saved: 1,000,000 contexts share only "
              << forest.distinct_type_count() << " heavy flyweight objects.\n";

    // Draw a few sample trees to show extrinsic state passed in
    std::cout << "\n--- Sample draws ---\n";
    Forest sample;
    sample.plant_tree(10, 20, "Oak", "Green", "oak.png");
    sample.plant_tree(35, 40, "Pine", "DarkGreen", "pine.png");
    sample.plant_tree(50, 12, "Oak", "Green", "oak.png");  // reuses the Oak flyweight
    sample.draw();

    return 0;
}
