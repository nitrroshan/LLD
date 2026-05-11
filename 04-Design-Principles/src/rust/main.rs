// Chapter 04 — Design Principles in Rust
// Rust naturally favors composition — no inheritance to abuse!
// Run: rustc main.rs && ./main

mod weapon;
mod movement;
mod character;

use weapon::*;
use movement::*;
use character::*;

fn main() {
    println!("=== Composition over Inheritance ===\n");

    let mut knight = GameCharacter::new("Arthur", Box::new(SwordWeapon), Box::new(WalkMovement));
    knight.attack();
    knight.do_move();

    println!();
    let mage = GameCharacter::new("Gandalf", Box::new(MagicWeapon), Box::new(TeleportMovement));
    mage.attack();
    mage.do_move();

    println!("\n--- Runtime Swap ---");
    println!("{} picks up a bow and learns to fly!\n", knight.name());
    knight.set_weapon(Box::new(BowWeapon));
    knight.set_movement(Box::new(FlyMovement));
    knight.attack();
    knight.do_move();
}
