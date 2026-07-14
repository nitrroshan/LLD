package chapter30;

/**
 * A member waiting for a title that is currently all loaned out.
 */
public class Reservation {
    private final Member member;
    private final String isbn;
    private final int day;

    public Reservation(Member member, String isbn, int day) {
        this.member = member;
        this.isbn = isbn;
        this.day = day;
    }

    public Member getMember() { return member; }
    public String getIsbn() { return isbn; }
    public int getDay() { return day; }
}
