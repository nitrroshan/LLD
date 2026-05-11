package chapter02;

/**
 * UML: Inheritance.
 * DigitalBook --|> Book  (DigitalBook IS-A Book)
 */
public class DigitalBook extends Book {
    private String format;     // PDF, EPUB, etc.
    private double fileSizeMb;

    public DigitalBook(String title, String isbn, Author author, String format, double fileSizeMb) {
        super(title, isbn, author);
        this.format = format;
        this.fileSizeMb = fileSizeMb;
    }

    public String getFormat() { return format; }
    public double getFileSizeMb() { return fileSizeMb; }

    @Override
    public void displayInfo() {
        System.out.println("[DigitalBook] " + getTitle() + " by " + getAuthor().getName()
                + " | Format: " + format + " | Size: " + fileSizeMb + "MB");
    }
}
