package chapter04;

/**
 * Composition — Weapon behavior interface.
 * Each weapon is a standalone, reusable, swappable component.
 */
public interface WeaponBehavior {
    void attack(String characterName);
}
