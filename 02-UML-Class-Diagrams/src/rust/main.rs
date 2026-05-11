// Chapter 02 — UML & Class Diagrams in Rust
// Run: rustc main.rs && ./main
//
// NOTE: Rust doesn't have inheritance. Instead:
//   - Enums replace class hierarchies (Book + DigitalBook → Book with BookKind enum)
//   - Traits replace interfaces (Searchable trait)
//   - Ownership replaces composition/aggregation distinction
//     (Vec<Book> = composition, &Member or Rc<Member> = aggregation)

mod author;
mod book;
mod member;
mod searchable;
mod library;

use author::Author;
use book::Book;
use member::Member;
use searchable::Searchable;
use library::Library;

fn main() {
    // --- Setup entities ---
    let _author1 = Author::new("Robert C. Martin", "uncle.bob@cleancode.com");
    let _author2 = Author::new("Erich Gamma", "erich@gof.com");

    // --- Composition: Library owns books ---
    let mut library = Library::new("City Library");
    library.add_book(Book::new("Clean Code", "978-0132350884", "Robert C. Martin"));
    library.add_book(Book::new("Design Patterns", "978-0201633610", "Erich Gamma"));
    library.add_book(Book::new_digital(
        "Clean Architecture", "978-0134494166", "Robert C. Martin", "PDF", 12.5,
    ));

    // --- Aggregation: Library has members ---
    library.register_member(Member::new("M001", "Alice"));
    library.register_member(Member::new("M002", "Bob"));

    // --- Realization: Library implements Searchable ---
    println!("=== SEARCH (Realization: Library implements Searchable) ===");
    if let Some(found) = library.search("Clean Code") {
        println!("Found: {} by {}", found.title(), found.author_name());
    }

    let by_author = library.search_by_author("Robert C. Martin");
    println!("Books by Robert C. Martin:");
    for b in &by_author {
        println!("  - {}", b.title());
    }

    // --- Dependency: Member uses Book ---
    println!("\n=== BORROW (Dependency: Member uses Book) ===");
    if let Some(book) = library.search("Clean Code") {
        library.members()[0].borrow_book(book);
    }
    if let Some(book) = library.search("Clean Architecture") {
        library.members()[1].borrow_book(book);
    }

    // --- Enum variant instead of inheritance ---
    println!("\n=== DIGITAL BOOK (Enum variant, not inheritance) ===");
    if let Some(book) = library.search("Clean Architecture") {
        book.display_info();
    }

    // --- Library state ---
    println!("\n=== LIBRARY STATE ===");
    library.display_info();
}
