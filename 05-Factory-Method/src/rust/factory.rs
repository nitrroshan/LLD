use crate::transport::*;

// Creator trait — factory method + business logic
// NOTE: Rust uses trait with default method instead of abstract class
pub trait LogisticsFactory {
    fn create_transport(&self) -> Box<dyn Transport>;

    fn plan_delivery(&self) {
        let transport = self.create_transport();
        println!("Planning delivery with: {}", transport.name());
        transport.deliver();
    }
}

// Concrete Creators
pub struct RoadLogistics;
impl LogisticsFactory for RoadLogistics {
    fn create_transport(&self) -> Box<dyn Transport> { Box::new(Truck) }
}

pub struct SeaLogistics;
impl LogisticsFactory for SeaLogistics {
    fn create_transport(&self) -> Box<dyn Transport> { Box::new(Ship) }
}

pub struct AirLogistics;
impl LogisticsFactory for AirLogistics {
    fn create_transport(&self) -> Box<dyn Transport> { Box::new(Airplane) }
}
