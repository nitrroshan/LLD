// Rust naturally favors composition over inheritance (no inheritance at all!)
// Traits = behaviors, structs compose via fields

pub trait WeaponBehavior {
    fn attack(&self, name: &str);
}

pub struct SwordWeapon;
impl WeaponBehavior for SwordWeapon {
    fn attack(&self, name: &str) { println!("{} swings a sword!", name); }
}

pub struct BowWeapon;
impl WeaponBehavior for BowWeapon {
    fn attack(&self, name: &str) { println!("{} shoots an arrow!", name); }
}

pub struct MagicWeapon;
impl WeaponBehavior for MagicWeapon {
    fn attack(&self, name: &str) { println!("{} casts a fireball!", name); }
}
