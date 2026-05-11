use crate::weapon::WeaponBehavior;
use crate::movement::MovementBehavior;

pub struct GameCharacter {
    name: String,
    weapon: Box<dyn WeaponBehavior>,
    movement: Box<dyn MovementBehavior>,
}

impl GameCharacter {
    pub fn new(name: &str, weapon: Box<dyn WeaponBehavior>, movement: Box<dyn MovementBehavior>) -> Self {
        GameCharacter { name: name.to_string(), weapon, movement }
    }

    pub fn attack(&self) { self.weapon.attack(&self.name); }
    pub fn do_move(&self) { self.movement.do_move(&self.name); }

    pub fn set_weapon(&mut self, w: Box<dyn WeaponBehavior>) { self.weapon = w; }
    pub fn set_movement(&mut self, m: Box<dyn MovementBehavior>) { self.movement = m; }

    pub fn name(&self) -> &str { &self.name }
}
