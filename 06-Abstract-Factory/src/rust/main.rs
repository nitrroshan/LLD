// Chapter 06 — Abstract Factory Pattern in Rust
// Run: rustc main.rs && ./main

mod products;
mod factory;

use factory::*;

// Client function — works with UIFactory trait only
fn build_ui(factory: &dyn UIFactory) {
    let button = factory.create_button();
    let checkbox = factory.create_checkbox();
    let menu = factory.create_menu();

    println!("--- Rendering UI ---");
    button.render();
    checkbox.render();
    menu.render();

    println!("--- Interacting ---");
    button.on_click();
    checkbox.toggle();
    menu.select("File > Save");
}

fn main() {
    println!("=== Windows UI ===");
    build_ui(&WindowsFactory);

    println!("\n=== Mac UI ===");
    build_ui(&MacFactory);

    // Runtime family selection
    println!("\n=== Runtime Selection (simulated) ===");
    let os = "mac";
    let factory: Box<dyn UIFactory> = if os == "windows" {
        Box::new(WindowsFactory)
    } else {
        Box::new(MacFactory)
    };
    build_ui(&*factory);
}
