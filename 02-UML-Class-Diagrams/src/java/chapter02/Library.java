package chapter02;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * UML: Composition source + Aggregation source + Realization.
 * Library *-- Book       (Composition — Library owns Books)
 * Library o-- Member     (Aggregation — Library has Members)
 * Library ..|> Searchable (Realization — implements interface)
 */
public class Library implements Searchable {
    private String name;
    private List<Book> books;         // Composition: Library owns these
    private List<Member> members;     // Aggregation: Library has these, but doesn't own their lifecycle

    public Library(String name) {
        this.name = name;
        this.books = new ArrayList<>();
        this.members = new ArrayList<>();
    }

    // --- Composition: Library manages Book lifecycle ---
    public void addBook(Book book) {
        books.add(book);
    }

    public void removeBook(Book book) {
        books.remove(book);
    }

    // --- Aggregation: Library registers/unregisters Members ---
    public void registerMember(Member member) {
        members.add(member);
    }

    public void unregisterMember(Member member) {
        members.remove(member);
    }

    // --- Realization: implements Searchable ---
    @Override
    public Book search(String title) {
        return books.stream()
                .filter(b -> b.getTitle().equalsIgnoreCase(title))
                .findFirst()
                .orElse(null);
    }

    @Override
    public List<Book> searchByAuthor(String authorName) {
        return books.stream()
                .filter(b -> b.getAuthor().getName().equalsIgnoreCase(authorName))
                .collect(Collectors.toList());
    }

    public void displayInfo() {
        System.out.println("Library: " + name);
        System.out.println("Books (" + books.size() + "):");
        books.forEach(b -> System.out.println("  - " + b));
        System.out.println("Members (" + members.size() + "):");
        members.forEach(m -> System.out.println("  - " + m));
    }
}
