package chapter34;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Splitwise Demo ===\n");

        User alice = new User("U1", "Alice");
        User bob = new User("U2", "Bob");
        User carol = new User("U3", "Carol");

        Group group = new Group("Trip");
        group.addMember(alice);
        group.addMember(bob);
        group.addMember(carol);
        group.addObserver(new NotificationObserver());

        List<User> all = Arrays.asList(alice, bob, carol);

        // 1) Equal split — Alice pays $90 dinner, split 3 ways ($30 each).
        System.out.println("Expense 1 (equal split):");
        group.addExpense("Dinner", 90.0, alice, all, new EqualSplitStrategy());

        // 2) Exact split — Bob pays $60 taxi; exact amounts.
        System.out.println("\nExpense 2 (exact split):");
        Map<String, Double> exact = new HashMap<>();
        exact.put("U1", 20.0);   // Alice
        exact.put("U2", 25.0);   // Bob
        exact.put("U3", 15.0);   // Carol
        group.addExpense("Taxi", 60.0, bob, all, new ExactSplitStrategy(exact));

        // 3) Percentage split — Carol pays $50 tickets; percentages.
        System.out.println("\nExpense 3 (percentage split):");
        Map<String, Double> pct = new HashMap<>();
        pct.put("U1", 50.0);
        pct.put("U2", 30.0);
        pct.put("U3", 20.0);
        group.addExpense("Tickets", 50.0, carol, all, new PercentSplitStrategy(pct));

        System.out.println();
        group.showBalances();

        System.out.println("\nSimplified settlements (fewest transactions):");
        for (Settlement s : group.simplify()) {
            System.out.printf("  %s pays %s $%.2f%n", s.getFrom().getName(), s.getTo().getName(), s.getAmount());
        }
    }
}
