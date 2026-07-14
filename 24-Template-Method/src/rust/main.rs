mod beverage;
mod tea;
mod coffee;
mod black_coffee;

use beverage::CaffeineBeverage;
use tea::Tea;
use coffee::Coffee;
use black_coffee::BlackCoffee;

fn main() {
    println!("=== Template Method Pattern Demo (Rust) ===\n");

    println!("Making tea:");
    Tea.prepare_recipe();

    println!("\nMaking coffee:");
    Coffee.prepare_recipe();

    println!("\nMaking black coffee (hook skips condiments):");
    BlackCoffee.prepare_recipe();

    println!("\nEvery beverage followed the SAME fixed sequence —");
    println!("only the brew and condiment steps varied.");
}
