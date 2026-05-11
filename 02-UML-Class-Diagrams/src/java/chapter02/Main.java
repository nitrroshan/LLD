package chapter02;

import java.util.List;

/**
 * Demonstrates UML relationships mapped to Java code.
 *
 * UML Relationships shown:
 *   Library  *-- Book       (Composition — Library owns Books)
 *   Book     --> Author     (Association — Book knows Author)
 *   Member   ..> Book       (Dependency — Member uses Book in method)
 *   Library  o-- Member     (Aggregation — Library has Members, they exist independently)
 *   Digital  --|> Book      (Inheritance — DigitalBook extends Book)
 *   Searchable <|.. Library (Realization — Library implements Searchable)
 */
public class Main {
    public static void main(String[] args) {
        // --- Setup entities ---
        Author author1 = new Author("Robert C. Martin", "uncle.bob@cleancode.com");
        Author author2 = new Author("Erich Gamma", "erich@gof.com");

        Book book1 = new Book("Clean Code", "978-0132350884", author1);
        Book book2 = new Book("Design Patterns", "978-0201633610", author2);
        DigitalBook ebook = new DigitalBook("Clean Architecture", "978-0134494166", author1, "PDF", 12.5);

        // --- Composition: Library owns books ---
        Library library = new Library("City Library");
        library.addBook(book1);
        library.addBook(book2);
        library.addBook(ebook);

        // --- Aggregation: Library has members (but members exist independently) ---
        Member alice = new Member("M001", "Alice");
        Member bob = new Member("M002", "Bob");
        library.registerMember(alice);
        library.registerMember(bob);

        // --- Realization: Library implements Searchable ---
        System.out.println("=== SEARCH (Realization: Library implements Searchable) ===");
        Book found = library.search("Clean Code");
        System.out.println("Found: " + found);

        List<Book> byAuthor = library.searchByAuthor("Robert C. Martin");
        System.out.println("Books by Robert C. Martin: " + byAuthor);

        // --- Dependency: Member uses Book in borrow() ---
        System.out.println("\n=== BORROW (Dependency: Member uses Book) ===");
        alice.borrow(book1);
        bob.borrow(ebook);

        // --- Inheritance: DigitalBook extends Book ---
        System.out.println("\n=== DIGITAL BOOK (Inheritance: DigitalBook extends Book) ===");
        ebook.displayInfo();

        // --- Association: Book knows its Author ---
        System.out.println("\n=== ASSOCIATION: Book --> Author ===");
        System.out.println(book1.getTitle() + " by " + book1.getAuthor().getName());
        System.out.println(book2.getTitle() + " by " + book2.getAuthor().getName());

        // --- Library info ---
        System.out.println("\n=== LIBRARY STATE ===");
        library.displayInfo();
    }
}
