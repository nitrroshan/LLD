use crate::book::Book;
use crate::member::Member;
use crate::searchable::Searchable;

/// Composition: Library owns Books (Vec<Book> = owned)
/// Aggregation: Library references Members (Vec<&Member> would be aggregation,
///   but Rust lifetimes make this complex, so we store owned Members for simplicity
///   and note the UML distinction in comments)
pub struct Library {
    name: String,
    books: Vec<Book>,       // Composition: Library owns these
    members: Vec<Member>,   // Aggregation conceptually (members exist independently)
}

impl Library {
    pub fn new(name: &str) -> Self {
        Library {
            name: name.to_string(),
            books: Vec::new(),
            members: Vec::new(),
        }
    }

    pub fn add_book(&mut self, book: Book) {
        self.books.push(book);
    }

    pub fn register_member(&mut self, member: Member) {
        self.members.push(member);
    }

    pub fn display_info(&self) {
        println!("Library: {}", self.name);
        println!("Books ({}):", self.books.len());
        for b in &self.books {
            println!("  - {} by {}", b.title(), b.author_name());
        }
        println!("Members ({}):", self.members.len());
        for m in &self.members {
            println!("  - {} ({})", m.name(), m.member_id());
        }
    }

    pub fn members(&self) -> &[Member] {
        &self.members
    }

    pub fn books(&self) -> &[Book] {
        &self.books
    }
}

// Realization: Library implements Searchable trait
impl Searchable for Library {
    fn search(&self, title: &str) -> Option<&Book> {
        self.books.iter().find(|b| b.title().eq_ignore_ascii_case(title))
    }

    fn search_by_author(&self, author_name: &str) -> Vec<&Book> {
        self.books
            .iter()
            .filter(|b| b.author_name().eq_ignore_ascii_case(author_name))
            .collect()
    }
}
