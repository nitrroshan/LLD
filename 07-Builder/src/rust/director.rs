use crate::house::{House, HouseBuilder};

pub struct HouseDirector;

impl HouseDirector {
    pub fn build_luxury_house() -> House {
        HouseBuilder::new()
            .rooms(6)
            .floors(3)
            .garage()
            .pool()
            .garden()
            .roof_type("slate")
            .build()
    }

    pub fn build_simple_house() -> House {
        HouseBuilder::new()
            .rooms(2)
            .floors(1)
            .roof_type("shingle")
            .build()
    }

    pub fn build_family_house() -> House {
        HouseBuilder::new()
            .rooms(4)
            .floors(2)
            .garage()
            .garden()
            .roof_type("tile")
            .build()
    }
}
