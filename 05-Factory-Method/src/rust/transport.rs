// Product trait
pub trait Transport {
    fn deliver(&self);
    fn name(&self) -> &str;
}

pub struct Truck;
impl Transport for Truck {
    fn deliver(&self) { println!("Delivering by land in a truck."); }
    fn name(&self) -> &str { "Truck" }
}

pub struct Ship;
impl Transport for Ship {
    fn deliver(&self) { println!("Delivering by sea in a container ship."); }
    fn name(&self) -> &str { "Ship" }
}

pub struct Airplane;
impl Transport for Airplane {
    fn deliver(&self) { println!("Delivering by air in a cargo airplane."); }
    fn name(&self) -> &str { "Airplane" }
}
