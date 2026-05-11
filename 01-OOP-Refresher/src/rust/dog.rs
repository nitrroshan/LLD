use crate::animal::Animal;

pub struct Dog {
    name: String,
    breed: String,
}

impl Dog {
    pub fn new(name: &str, breed: &str) -> Self {
        Dog {
            name: name.to_string(),
            breed: breed.to_string(),
        }
    }

    pub fn fetch(&self) {
        println!("{} fetches the ball!", self.name);
    }
}

impl Animal for Dog {
    fn name(&self) -> &str {
        &self.name
    }

    fn make_sound(&self) {
        println!("{} says Woof! [{}]", self.name, self.breed);
    }
}
