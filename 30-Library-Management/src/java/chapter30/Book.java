package chapter30;

import java.util.ArrayList;
import java.util.List;

/**
 * A catalog entry (title) that owns its physical copies. Availability is
 * derived from the copies' statuses.
 */
public class Book {
    private final String isbn;
    private final String title;
    private final String author;
    private final List<BookItem> items = new ArrayList<>();

    public Book(String isbn, String title, String author) {
        this.isbn = isbn;
        this.title = title;
        this.author = author;
    }

    public String getIsbn() { return isbn; }
    public String getTitle() { return title; }
    public String getAuthor() { return author; }

    public void addItem(BookItem item) {
        items.add(item);
    }

    public BookItem findAvailableItem() {
        for (BookItem item : items) {
            if (item.getStatus() == BookStatus.AVAILABLE) {
                return item;
            }
        }
        return null;
    }

    public int availableCount() {
        int count = 0;
        for (BookItem item : items) {
            if (item.getStatus() == BookStatus.AVAILABLE) {
                count++;
            }
        }
        return count;
    }

    public int totalCount() {
        return items.size();
    }
}
