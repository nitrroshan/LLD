/// Association target: Book knows Author, Author exists independently
pub struct Author {
    name: String,
    email: String,
}

impl Author {
    pub fn new(name: &str, email: &str) -> Self {
        Author {
            name: name.to_string(),
            email: email.to_string(),
        }
    }

    pub fn name(&self) -> &str {
        &self.name
    }

    pub fn email(&self) -> &str {
        &self.email
    }
}
