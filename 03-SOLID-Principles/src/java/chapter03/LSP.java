package chapter03;

/**
 * LSP — Liskov Substitution Principle
 *
 * BAD:  Penguin extends Bird but can't fly — breaks caller's expectations.
 * GOOD: Separate interfaces for flying and non-flying birds.
 */
public class LSP {

    // ===================== BAD =====================
    static class Bird {
        String name;
        Bird(String name) { this.name = name; }

        void fly() {
            System.out.println(name + " is flying!");
        }
    }

    static class Penguin extends Bird {
        Penguin() { super("Penguin"); }

        @Override
        void fly() {
            throw new UnsupportedOperationException("Penguins can't fly!");
            // Violates LSP: callers expect all Birds to fly
        }
    }

    static void makeBirdFly(Bird bird) {
        bird.fly();  // Crashes for Penguin!
    }

    // ===================== GOOD =====================
    interface BirdLike {
        String getName();
    }

    interface Flyable {
        void fly();
    }

    static class Sparrow implements BirdLike, Flyable {
        public String getName() { return "Sparrow"; }
        public void fly() { System.out.println("Sparrow is flying!"); }
    }

    static class PenguinGood implements BirdLike {
        public String getName() { return "Penguin"; }
        // No fly() — Penguin doesn't implement Flyable
        void swim() { System.out.println("Penguin is swimming!"); }
    }

    static void makeFly(Flyable f) {
        f.fly();  // Only called with things that CAN fly
    }

    // ===================== DEMO =====================
    public static void main(String[] args) {
        System.out.println("=== BAD (Penguin extends Bird but can't fly) ===");
        makeBirdFly(new Bird("Eagle"));
        try {
            makeBirdFly(new Penguin());  // CRASH!
        } catch (UnsupportedOperationException e) {
            System.out.println("ERROR: " + e.getMessage());
        }

        System.out.println("\n=== GOOD (separate Flyable interface) ===");
        Sparrow sparrow = new Sparrow();
        PenguinGood penguin = new PenguinGood();

        makeFly(sparrow);       // ✅ Sparrow can fly
        // makeFly(penguin);    // Won't compile — PenguinGood doesn't implement Flyable
        penguin.swim();         // ✅ Penguin does what it CAN do
    }
}
