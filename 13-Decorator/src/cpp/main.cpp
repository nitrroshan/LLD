#include <iostream>
#include <iomanip>
#include <memory>
#include "Espresso.h"
#include "Latte.h"
#include "MilkDecorator.h"
#include "WhipDecorator.h"
#include "CaramelDecorator.h"

void print_coffee(const std::string& label, const Coffee& coffee) {
    std::cout << "  " << std::left << std::setw(15) << (label + ":")
              << coffee.get_description() << " — $"
              << std::fixed << std::setprecision(2) << coffee.get_cost() << "\n";
}

int main() {
    std::cout << "=== Decorator Pattern Demo (C++) ===\n\n";

    // 1. Plain espresso
    auto plain = std::make_unique<Espresso>();
    print_coffee("Plain", *plain);

    // 2. Espresso + Milk
    auto with_milk = std::make_unique<MilkDecorator>(std::make_unique<Espresso>());
    print_coffee("With milk", *with_milk);

    // 3. Stacked: Espresso + Milk + Whip + Caramel
    auto loaded = std::make_unique<CaramelDecorator>(
                    std::make_unique<WhipDecorator>(
                      std::make_unique<MilkDecorator>(
                        std::make_unique<Espresso>())));
    print_coffee("Loaded", *loaded);

    // 4. Latte + Whip
    auto latte_whip = std::make_unique<WhipDecorator>(std::make_unique<Latte>());
    print_coffee("Latte+Whip", *latte_whip);

    // 5. Double milk
    auto double_milk = std::make_unique<MilkDecorator>(
                         std::make_unique<MilkDecorator>(
                           std::make_unique<Espresso>()));
    print_coffee("Double milk", *double_milk);

    return 0;
}
