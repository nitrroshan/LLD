mod tree_type;
mod tree_factory;
mod tree;
mod forest;

use forest::Forest;

fn main() {
    println!("=== Flyweight Pattern Demo (Rust) ===\n");

    let mut forest = Forest::new();

    // Plant 1,000,000 trees, but only 3 distinct types
    println!("Planting 1,000,000 trees...");
    let species = [
        ("Oak", "Green", "oak.png"),
        ("Pine", "DarkGreen", "pine.png"),
        ("Cherry", "Pink", "cherry.png"),
    ];

    for i in 0..1_000_000 {
        let (name, color, texture) = species[i % species.len()];
        forest.plant_tree((i % 800) as i32, (i % 600) as i32, name, color, texture);
    }

    println!("\nResult:");
    println!("  Trees planted:        {}", forest.tree_count());
    println!("  Distinct TreeTypes:   {}", forest.distinct_type_count());
    println!(
        "  Memory saved: 1,000,000 contexts share only {} heavy flyweight objects.",
        forest.distinct_type_count()
    );

    // Draw a few sample trees to show extrinsic state passed in
    println!("\n--- Sample draws ---");
    let mut sample = Forest::new();
    sample.plant_tree(10, 20, "Oak", "Green", "oak.png");
    sample.plant_tree(35, 40, "Pine", "DarkGreen", "pine.png");
    sample.plant_tree(50, 12, "Oak", "Green", "oak.png"); // reuses the Oak flyweight
    sample.draw();
}
