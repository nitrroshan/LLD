package chapter04;

/**
 * BAD: Inheritance-based character system.
 * Each combination of weapon + movement needs its own subclass → explosion.
 *
 * Violates: Composition > Inheritance, DRY, OCP
 */
public class InheritanceBad {

    static abstract class Character {
        String name;
        Character(String name) { this.name = name; }
        abstract void attack();
        abstract void move();
    }

    // Sword + Walk
    static class Knight extends Character {
        Knight(String name) { super(name); }
        void attack() { System.out.println(name + " swings a sword!"); }
        void move() { System.out.println(name + " walks."); }
    }

    // Bow + Walk
    static class Archer extends Character {
        Archer(String name) { super(name); }
        void attack() { System.out.println(name + " shoots an arrow!"); }
        void move() { System.out.println(name + " walks."); }  // DRY violation: same as Knight
    }

    // Sword + Fly   →  need ANOTHER subclass!
    static class FlyingKnight extends Character {
        FlyingKnight(String name) { super(name); }
        void attack() { System.out.println(name + " swings a sword!"); }  // DRY: same as Knight
        void move() { System.out.println(name + " flies!"); }
    }

    // Bow + Fly  →  yet another!
    // Magic + Walk? Magic + Fly? Magic + Teleport?
    // → N weapons × M movements = N×M subclasses!

    public static void main(String[] args) {
        System.out.println("=== BAD: Inheritance explosion ===");
        Character knight = new Knight("Arthur");
        knight.attack();
        knight.move();

        Character archer = new Archer("Robin");
        archer.attack();
        archer.move();

        Character flyKnight = new FlyingKnight("Pegasus Knight");
        flyKnight.attack();
        flyKnight.move();

        System.out.println("\nProblem: Adding Teleport movement requires 3+ new classes!");
    }
}
