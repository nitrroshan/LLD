use crate::animal::Animal;

pub struct Cat {
    name: String,
}

impl Cat {
    pub fn new(name: &str) -> Self {
        Cat {
            name: name.to_string(),
        }
    }

    pub fn purr(&self) {
        println!("{} is purring...", self.name);
    }
}

impl Animal for Cat {
    fn name(&self) -> &str {
        &self.name
    }

    fn make_sound(&self) {
        println!("{} says Meow!", self.name);
    }
}
