package chapter02;

/**
 * UML: Aggregation + Dependency.
 * Library o-- Member  (Aggregation — Library has Members, Members exist independently)
 * Member ..> Book     (Dependency — Member uses Book in borrow(), doesn't store it)
 */
public class Member {
    private String memberId;
    private String name;

    public Member(String memberId, String name) {
        this.memberId = memberId;
        this.name = name;
    }

    public String getMemberId() { return memberId; }
    public String getName() { return name; }

    // Dependency: Member uses Book (parameter only, not stored as field)
    public void borrow(Book book) {
        System.out.println(name + " borrowed: " + book.getTitle());
    }

    @Override
    public String toString() {
        return name + " (" + memberId + ")";
    }
}
