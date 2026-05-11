// Chapter 05 — Factory Method Pattern in Rust
// Run: rustc main.rs && ./main

mod transport;
mod factory;

use factory::*;

fn main() {
    println!("=== Road Logistics ===");
    RoadLogistics.plan_delivery();

    println!("\n=== Sea Logistics ===");
    SeaLogistics.plan_delivery();

    println!("\n=== Air Logistics ===");
    AirLogistics.plan_delivery();

    println!("\n=== All Logistics (trait objects) ===");
    let factories: Vec<&dyn LogisticsFactory> = vec![&RoadLogistics, &SeaLogistics, &AirLogistics];
    for f in factories {
        f.plan_delivery();
    }
}
