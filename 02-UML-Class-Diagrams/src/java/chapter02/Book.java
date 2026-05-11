package chapter02;

/**
 * UML: Composition target + Association source.
 * Library *-- Book  (Library owns Book — composition)
 * Book --> Author   (Book knows Author — association)
 */
public class Book {
    private String title;
    private String isbn;
    private Author author;  // Association: Book knows its Author

    public Book(String title, String isbn, Author author) {
        this.title = title;
        this.isbn = isbn;
        this.author = author;
    }

    public String getTitle() { return title; }
    public String getIsbn() { return isbn; }
    public Author getAuthor() { return author; }

    public void displayInfo() {
        System.out.println("[Book] " + title + " by " + author.getName() + " (ISBN: " + isbn + ")");
    }

    @Override
    public String toString() {
        return title + " by " + author.getName();
    }
}
