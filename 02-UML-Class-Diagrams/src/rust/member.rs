use crate::book::Book;

/// Dependency: Member uses Book in borrow() but doesn't own it
pub struct Member {
    member_id: String,
    name: String,
}

impl Member {
    pub fn new(member_id: &str, name: &str) -> Self {
        Member {
            member_id: member_id.to_string(),
            name: name.to_string(),
        }
    }

    pub fn name(&self) -> &str {
        &self.name
    }

    pub fn member_id(&self) -> &str {
        &self.member_id
    }

    // Dependency: borrows a reference to Book (doesn't store it)
    pub fn borrow_book(&self, book: &Book) {
        println!("{} borrowed: {}", self.name, book.title());
    }
}
