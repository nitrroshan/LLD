// Chapter 02 — UML & Class Diagrams in Go
// Run: go run .
//
// NOTE: Go has no inheritance or implements keyword.
//   - Embedding replaces inheritance (DigitalBook embeds Book)
//   - Interfaces are satisfied implicitly (Library satisfies Searchable)
//   - Ownership is managed by convention (pointers vs values)

package main

import "fmt"

func main() {
	// --- Setup entities ---
	author1 := NewAuthor("Robert C. Martin", "uncle.bob@cleancode.com")
	author2 := NewAuthor("Erich Gamma", "erich@gof.com")

	// --- Composition: Library owns books ---
	library := NewLibrary("City Library")
	library.AddBook(NewBook("Clean Code", "978-0132350884", author1))
	library.AddBook(NewBook("Design Patterns", "978-0201633610", author2))

	// Embedding: DigitalBook embeds Book — use .Book to get the inner *Book
	ebook := NewDigitalBook("Clean Architecture", "978-0134494166", author1, "PDF", 12.5)
	library.AddBook(ebook.Book) // Add the embedded Book to the library

	// --- Aggregation: Library has members ---
	alice := NewMember("M001", "Alice")
	bob := NewMember("M002", "Bob")
	library.RegisterMember(alice)
	library.RegisterMember(bob)

	// --- Realization: Library implements Searchable (implicitly) ---
	fmt.Println("=== SEARCH (Realization: Library implements Searchable) ===")
	var s Searchable = library // Library satisfies Searchable — no "implements" needed
	found := s.Search("Clean Code")
	if found != nil {
		fmt.Printf("Found: %s by %s\n", found.Title, found.Author.Name)
	}

	byAuthor := s.SearchByAuthor("Robert C. Martin")
	fmt.Println("Books by Robert C. Martin:")
	for _, b := range byAuthor {
		fmt.Printf("  - %s\n", b.Title)
	}

	// --- Dependency: Member uses Book ---
	fmt.Println("\n=== BORROW (Dependency: Member uses Book) ===")
	alice.Borrow(found)
	bob.Borrow(library.Search("Clean Architecture"))

	// --- Embedding (Go's "inheritance") ---
	fmt.Println("\n=== DIGITAL BOOK (Embedding, not inheritance) ===")
	ebook.DisplayInfo()

	// --- Library state ---
	fmt.Println("\n=== LIBRARY STATE ===")
	library.DisplayInfo()
}
