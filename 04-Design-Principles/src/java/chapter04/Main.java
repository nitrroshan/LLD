package chapter04;

/**
 * GOOD: Demonstrates Composition > Inheritance, DRY, KISS, YAGNI, Law of Demeter.
 *
 * Compile & Run:
 *   cd 04-Design-Principles/src/java
 *   javac chapter04/*.java
 *   java chapter04.Main
 */
public class Main {
    public static void main(String[] args) {
        System.out.println("══════ BAD: Inheritance Explosion ══════");
        InheritanceBad.main(args);

        System.out.println("\n══════ GOOD: Composition ══════");
        System.out.println("--- Characters (mix and match freely) ---\n");

        GameCharacter knight = new GameCharacter("Arthur", new SwordWeapon(), new WalkMovement());
        knight.attack();
        knight.move();

        System.out.println();
        GameCharacter archer = new GameCharacter("Robin", new BowWeapon(), new WalkMovement());
        archer.attack();
        archer.move();

        System.out.println();
        GameCharacter mage = new GameCharacter("Gandalf", new MagicWeapon(), new TeleportMovement());
        mage.attack();
        mage.move();

        // Runtime behavior swap — only possible with composition!
        System.out.println("\n--- Runtime Swap ---");
        System.out.println(knight.getName() + " picks up a bow and learns to fly!\n");
        knight.setWeapon(new BowWeapon());
        knight.setMovement(new FlyMovement());
        knight.attack();
        knight.move();

        // DRY: WalkMovement is reused by Knight and Archer — defined once
        // KISS: No factories or abstract builders — just constructors
        // YAGNI: No unused weapon/movement types — add them when needed
        // Demeter: Main talks to GameCharacter only, not its internals
    }
}
