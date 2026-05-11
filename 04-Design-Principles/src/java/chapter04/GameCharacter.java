package chapter04;

/**
 * GOOD: Character composed of behaviors.
 * No subclasses needed — mix and match weapon + movement freely.
 * Behaviors can even be swapped at runtime!
 */
public class GameCharacter {
    private String name;
    private WeaponBehavior weapon;
    private MovementBehavior movement;

    public GameCharacter(String name, WeaponBehavior weapon, MovementBehavior movement) {
        this.name = name;
        this.weapon = weapon;
        this.movement = movement;
    }

    public void attack() { weapon.attack(name); }
    public void move() { movement.move(name); }

    // Swap behaviors at runtime — impossible with inheritance!
    public void setWeapon(WeaponBehavior weapon) { this.weapon = weapon; }
    public void setMovement(MovementBehavior movement) { this.movement = movement; }

    public String getName() { return name; }
}
