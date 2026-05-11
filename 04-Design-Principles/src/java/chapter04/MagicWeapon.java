package chapter04;

public class MagicWeapon implements WeaponBehavior {
    public void attack(String name) {
        System.out.println(name + " casts a fireball!");
    }
}
