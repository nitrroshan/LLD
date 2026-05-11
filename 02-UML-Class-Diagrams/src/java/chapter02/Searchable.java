package chapter02;

import java.util.List;

/**
 * UML: Realization (interface).
 * Library implements Searchable.
 */
public interface Searchable {
    Book search(String title);
    List<Book> searchByAuthor(String authorName);
}
