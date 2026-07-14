mod coffee;
mod base_coffees;
mod decorators;

use coffee::Coffee;
use base_coffees::{Espresso, Latte};
use decorators::{MilkDecorator, WhipDecorator, CaramelDecorator};

fn print_coffee(label: &str, coffee: &dyn Coffee) {
    println!("  {:<15} {} — ${:.2}", format!("{}:", label), coffee.get_description(), coffee.get_cost());
}

fn main() {
    println!("=== Decorator Pattern Demo (Rust) ===\n");

    // 1. Plain espresso
    let plain = Espresso;
    print_coffee("Plain", &plain);

    // 2. Espresso + Milk
    let with_milk = MilkDecorator::new(Box::new(Espresso));
    print_coffee("With milk", &with_milk);

    // 3. Stacked: Espresso + Milk + Whip + Caramel
    let loaded = CaramelDecorator::new(
        Box::new(WhipDecorator::new(
            Box::new(MilkDecorator::new(
                Box::new(Espresso))))));
    print_coffee("Loaded", &loaded);

    // 4. Latte + Whip
    let latte_whip = WhipDecorator::new(Box::new(Latte));
    print_coffee("Latte+Whip", &latte_whip);

    // 5. Double milk
    let double_milk = MilkDecorator::new(
        Box::new(MilkDecorator::new(
            Box::new(Espresso))));
    print_coffee("Double milk", &double_milk);
}
