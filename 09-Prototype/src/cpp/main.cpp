#include <iostream>
#include <memory>
#include "Circle.h"
#include "Rectangle.h"
#include "ShapeRegistry.h"

int main() {
    std::cout << "=== Prototype Pattern Demo (C++) ===\n\n";

    // 1. Create originals
    Circle original_circle(0, 0, "red", 10);
    original_circle.add_tag("template");
    original_circle.add_tag("primary");

    Rectangle original_rect(0, 0, "blue", 100, 50);
    original_rect.add_tag("template");

    std::cout << "--- Originals ---\n";
    std::cout << "Original: " << original_circle.to_string() << "\n";
    std::cout << "Original: " << original_rect.to_string() << "\n\n";

    // 2. Clone and customize
    std::cout << "--- Clone & Customize ---\n";
    auto clone1 = original_circle.clone();
    clone1->move_to(10, 20);
    clone1->add_tag("clone-1");

    auto clone2 = original_circle.clone();
    clone2->move_to(30, 40);
    clone2->add_tag("clone-2");

    std::cout << "Clone 1:  " << clone1->to_string() << "\n";
    std::cout << "Clone 2:  " << clone2->to_string() << "\n";
    std::cout << "Original: " << original_circle.to_string() << "\n";
    std::cout << "  ^ tags unchanged — deep copy worked!\n\n";

    // 3. Polymorphic cloning
    std::cout << "--- Polymorphic Cloning ---\n";
    const Shape& shape_ref = original_circle;
    auto cloned = shape_ref.clone();  // clones a Circle through Shape reference
    std::cout << "Cloned via Shape ref: " << cloned->to_string() << "\n\n";

    // 4. Prototype Registry
    std::cout << "--- Prototype Registry ---\n";
    ShapeRegistry registry;
    registry.register_shape("red-circle", std::make_unique<Circle>(0, 0, "red", 10));
    registry.register_shape("blue-rect", std::make_unique<Rectangle>(0, 0, "blue", 100, 50));

    auto s1 = registry.get("red-circle");
    auto s2 = registry.get("red-circle");
    auto s3 = registry.get("blue-rect");

    s1->move_to(10, 10);
    s2->move_to(50, 50);
    s3->move_to(100, 100);

    std::cout << "From registry: " << s1->to_string() << "\n";
    std::cout << "From registry: " << s2->to_string() << "\n";
    std::cout << "From registry: " << s3->to_string() << "\n";
    std::cout << "Same object? " << (s1.get() == s2.get() ? "true" : "false") << "\n";

    return 0;
}
