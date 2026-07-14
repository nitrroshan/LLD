package chapter30;

/**
 * A single physical copy of a book, identified by a barcode. Holds its loan
 * status and, when loaned, the day it is due.
 */
public class BookItem {
    private final String barcode;
    private final String isbn;
    private BookStatus status = BookStatus.AVAILABLE;
    private int dueDay;

    public BookItem(String barcode, String isbn) {
        this.barcode = barcode;
        this.isbn = isbn;
    }

    public String getBarcode() { return barcode; }
    public String getIsbn() { return isbn; }
    public BookStatus getStatus() { return status; }
    public void setStatus(BookStatus status) { this.status = status; }
    public int getDueDay() { return dueDay; }
    public void setDueDay(int dueDay) { this.dueDay = dueDay; }
}
