package chapter30;

/**
 * Student policy: up to 3 books for 14 days.
 */
public class StudentMember extends Member {
    public StudentMember(String id, String name) {
        super(id, name);
    }

    @Override
    public int maxBooks() {
        return 3;
    }

    @Override
    public int loanPeriodDays() {
        return 14;
    }
}
