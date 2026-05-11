mod shapes;
mod registry;

use shapes::{Circle, Rectangle, Prototype};
use registry::ShapeRegistry;

fn main() {
    println!("=== Prototype Pattern Demo (Rust) ===\n");

    // 1. Create originals
    let mut original_circle = Circle::new(0, 0, "red", 10);
    original_circle.add_tag("template");
    original_circle.add_tag("primary");

    let mut original_rect = Rectangle::new(0, 0, "blue", 100, 50);
    original_rect.add_tag("template");

    println!("--- Originals ---");
    println!("Original: {}", original_circle);
    println!("Original: {}", original_rect);
    println!();

    // 2. Clone and customize
    println!("--- Clone & Customize ---");
    let mut clone1 = original_circle.clone_shape();
    clone1.move_to(10, 20);
    clone1.add_tag("clone-1");

    let mut clone2 = original_circle.clone_shape();
    clone2.move_to(30, 40);
    clone2.add_tag("clone-2");

    println!("Clone 1:  {}", clone1);
    println!("Clone 2:  {}", clone2);
    println!("Original: {}", original_circle);
    println!("  ^ tags unchanged — deep copy worked!");
    println!();

    // 3. Polymorphic cloning — clone through trait object
    println!("--- Polymorphic Cloning ---");
    let shape_ref: &dyn Prototype = &original_circle;
    let cloned = shape_ref.clone_shape();
    println!("Cloned via trait ref: {}", cloned);
    println!();

    // 4. Prototype Registry
    println!("--- Prototype Registry ---");
    let mut registry = ShapeRegistry::new();
    registry.register("red-circle", Box::new(Circle::new(0, 0, "red", 10)));
    registry.register("blue-rect", Box::new(Rectangle::new(0, 0, "blue", 100, 50)));

    let mut s1 = registry.get("red-circle");
    let mut s2 = registry.get("red-circle");
    let mut s3 = registry.get("blue-rect");

    s1.move_to(10, 10);
    s2.move_to(50, 50);
    s3.move_to(100, 100);

    println!("From registry: {}", s1);
    println!("From registry: {}", s2);
    println!("From registry: {}", s3);
}
