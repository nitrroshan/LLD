package chapter09;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Prototype Pattern Demo ===\n");

        // 1. Create original shapes
        Circle originalCircle = new Circle(0, 0, "red", 10);
        originalCircle.addTag("template");
        originalCircle.addTag("primary");

        Rectangle originalRect = new Rectangle(0, 0, "blue", 100, 50);
        originalRect.addTag("template");

        System.out.println("--- Originals ---");
        System.out.println("Original: " + originalCircle);
        System.out.println("Original: " + originalRect);
        System.out.println();

        // 2. Clone and customize
        System.out.println("--- Clone & Customize ---");
        Circle clone1 = originalCircle.clone();
        clone1.moveTo(10, 20);
        clone1.addTag("clone-1");

        Circle clone2 = originalCircle.clone();
        clone2.moveTo(30, 40);
        clone2.addTag("clone-2");

        System.out.println("Clone 1:  " + clone1);
        System.out.println("Clone 2:  " + clone2);
        System.out.println("Original: " + originalCircle);
        System.out.println("  ^ tags unchanged — deep copy worked!");
        System.out.println();

        // 3. Polymorphic cloning — clone through Shape reference
        System.out.println("--- Polymorphic Cloning ---");
        Shape shapeRef = originalCircle;     // only know it's a Shape
        Shape cloned = shapeRef.clone();     // still clones a Circle!
        System.out.println("Cloned via Shape ref: " + cloned);
        System.out.println("Type: " + cloned.getClass().getSimpleName());
        System.out.println();

        // 4. Prototype Registry
        System.out.println("--- Prototype Registry ---");
        ShapeRegistry registry = new ShapeRegistry();
        registry.register("red-circle", new Circle(0, 0, "red", 10));
        registry.register("blue-rect", new Rectangle(0, 0, "blue", 100, 50));
        registry.register("small-green-circle", new Circle(0, 0, "green", 5));

        Shape s1 = registry.get("red-circle");
        Shape s2 = registry.get("red-circle");
        Shape s3 = registry.get("blue-rect");

        s1.moveTo(10, 10);
        s2.moveTo(50, 50);
        s3.moveTo(100, 100);

        System.out.println("From registry: " + s1);
        System.out.println("From registry: " + s2);
        System.out.println("From registry: " + s3);
        System.out.println("Same object? " + (s1 == s2));  // false — different clones
    }
}
