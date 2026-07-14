package chapter34;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Tracks directed pairwise debts (debtor -> creditor -> amount), netting
 * opposing debts, and can simplify everything to the fewest settlements.
 */
public class BalanceSheet {
    private final Map<User, Map<User, Double>> owes = new HashMap<>();

    private double amountOwed(User debtor, User creditor) {
        return owes.getOrDefault(debtor, new HashMap<>()).getOrDefault(creditor, 0.0);
    }

    private void setOwed(User debtor, User creditor, double amount) {
        owes.computeIfAbsent(debtor, k -> new HashMap<>()).put(creditor, amount);
    }

    /** Record that debtor owes creditor, netting against any opposite debt. */
    public void addDebt(User debtor, User creditor, double amount) {
        double opposite = amountOwed(creditor, debtor);   // creditor owes debtor already?
        if (opposite >= amount) {
            setOwed(creditor, debtor, opposite - amount);
            return;
        }
        if (opposite > 0) {
            setOwed(creditor, debtor, 0.0);
            amount -= opposite;
        }
        setOwed(debtor, creditor, amountOwed(debtor, creditor) + amount);
    }

    public void show() {
        boolean any = false;
        for (Map.Entry<User, Map<User, Double>> e : owes.entrySet()) {
            for (Map.Entry<User, Double> c : e.getValue().entrySet()) {
                if (c.getValue() > 0.001) {
                    System.out.printf("  %s owes %s $%.2f%n", e.getKey(), c.getKey(), c.getValue());
                    any = true;
                }
            }
        }
        if (!any) {
            System.out.println("  All settled up.");
        }
    }

    /** Reduce all debts to the minimum number of settlements (min cash flow). */
    public List<Settlement> simplify(List<User> users) {
        Map<User, Double> net = new HashMap<>();
        for (User u : users) net.put(u, 0.0);
        for (Map.Entry<User, Map<User, Double>> e : owes.entrySet()) {
            for (Map.Entry<User, Double> c : e.getValue().entrySet()) {
                double amt = c.getValue();
                if (amt > 0.001) {
                    net.put(e.getKey(), net.get(e.getKey()) - amt);   // debtor
                    net.put(c.getKey(), net.get(c.getKey()) + amt);   // creditor
                }
            }
        }

        List<Settlement> settlements = new ArrayList<>();
        while (true) {
            User creditor = maxBy(net, true);
            User debtor = maxBy(net, false);
            if (creditor == null || debtor == null) break;
            double credit = net.get(creditor);
            double debt = -net.get(debtor);
            if (credit < 0.01 || debt < 0.01) break;
            double amount = Math.min(credit, debt);
            settlements.add(new Settlement(debtor, creditor, round(amount)));
            net.put(creditor, credit - amount);
            net.put(debtor, net.get(debtor) + amount);
        }
        return settlements;
    }

    private User maxBy(Map<User, Double> net, boolean positive) {
        User best = null;
        double bestVal = positive ? 0.01 : -0.01;
        for (Map.Entry<User, Double> e : net.entrySet()) {
            if (positive && e.getValue() > bestVal) { bestVal = e.getValue(); best = e.getKey(); }
            if (!positive && e.getValue() < bestVal) { bestVal = e.getValue(); best = e.getKey(); }
        }
        return best;
    }

    private double round(double v) {
        return Math.round(v * 100.0) / 100.0;
    }
}
