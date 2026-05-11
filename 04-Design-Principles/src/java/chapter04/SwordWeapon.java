package chapter04;

public class SwordWeapon implements WeaponBehavior {
    public void attack(String name) {
        System.out.println(name + " swings a sword!");
    }
}
