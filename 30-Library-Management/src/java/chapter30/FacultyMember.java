package chapter30;

/**
 * Faculty policy: up to 10 books for 30 days.
 */
public class FacultyMember extends Member {
    public FacultyMember(String id, String name) {
        super(id, name);
    }

    @Override
    public int maxBooks() {
        return 10;
    }

    @Override
    public int loanPeriodDays() {
        return 30;
    }
}
