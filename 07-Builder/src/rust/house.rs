use std::fmt;

pub struct House {
    rooms: u32,
    floors: u32,
    has_garage: bool,
    has_pool: bool,
    has_garden: bool,
    roof_type: String,
}

impl House {
    pub fn rooms(&self) -> u32 { self.rooms }
    pub fn floors(&self) -> u32 { self.floors }
    pub fn has_garage(&self) -> bool { self.has_garage }
    pub fn has_pool(&self) -> bool { self.has_pool }
    pub fn has_garden(&self) -> bool { self.has_garden }
    pub fn roof_type(&self) -> &str { &self.roof_type }
}

impl fmt::Display for House {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "House [{} rooms, {} floors, roof={}",
               self.rooms, self.floors, self.roof_type)?;
        if self.has_garage { write!(f, ", garage")?; }
        if self.has_pool { write!(f, ", pool")?; }
        if self.has_garden { write!(f, ", garden")?; }
        write!(f, "]")
    }
}

pub struct HouseBuilder {
    rooms: u32,
    floors: u32,
    has_garage: bool,
    has_pool: bool,
    has_garden: bool,
    roof_type: String,
}

impl HouseBuilder {
    pub fn new() -> Self {
        HouseBuilder {
            rooms: 1,
            floors: 1,
            has_garage: false,
            has_pool: false,
            has_garden: false,
            roof_type: String::from("shingle"),
        }
    }

    pub fn rooms(mut self, count: u32) -> Self {
        self.rooms = count;
        self
    }

    pub fn floors(mut self, count: u32) -> Self {
        self.floors = count;
        self
    }

    pub fn garage(mut self) -> Self {
        self.has_garage = true;
        self
    }

    pub fn pool(mut self) -> Self {
        self.has_pool = true;
        self
    }

    pub fn garden(mut self) -> Self {
        self.has_garden = true;
        self
    }

    pub fn roof_type(mut self, roof: &str) -> Self {
        self.roof_type = roof.to_string();
        self
    }

    pub fn build(self) -> House {
        assert!(self.rooms >= 1, "House must have at least 1 room");
        assert!(self.floors >= 1, "House must have at least 1 floor");

        House {
            rooms: self.rooms,
            floors: self.floors,
            has_garage: self.has_garage,
            has_pool: self.has_pool,
            has_garden: self.has_garden,
            roof_type: self.roof_type,
        }
    }
}
