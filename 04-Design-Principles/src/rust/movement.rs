pub trait MovementBehavior {
    fn do_move(&self, name: &str);
}

pub struct WalkMovement;
impl MovementBehavior for WalkMovement {
    fn do_move(&self, name: &str) { println!("{} walks.", name); }
}

pub struct FlyMovement;
impl MovementBehavior for FlyMovement {
    fn do_move(&self, name: &str) { println!("{} flies!", name); }
}

pub struct TeleportMovement;
impl MovementBehavior for TeleportMovement {
    fn do_move(&self, name: &str) { println!("{} teleports!", name); }
}
