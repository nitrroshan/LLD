package chapter04;

public class BowWeapon implements WeaponBehavior {
    public void attack(String name) {
        System.out.println(name + " shoots an arrow!");
    }
}
