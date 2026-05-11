mod house;
mod director;

use house::HouseBuilder;
use director::HouseDirector;

fn main() {
    println!("=== Builder Pattern Demo ===\n");

    // 1. Build a custom house step by step
    let custom_house = HouseBuilder::new()
        .rooms(4)
        .floors(2)
        .garage()
        .pool()
        .roof_type("tile")
        .build();
    println!("Custom:  {}", custom_house);

    // 2. Use the Director for pre-defined configurations
    let luxury = HouseDirector::build_luxury_house();
    println!("Luxury:  {}", luxury);

    let simple = HouseDirector::build_simple_house();
    println!("Simple:  {}", simple);

    let family = HouseDirector::build_family_house();
    println!("Family:  {}", family);

    // 3. Minimal house — only defaults
    let minimal = HouseBuilder::new().build();
    println!("Minimal: {}", minimal);
}
