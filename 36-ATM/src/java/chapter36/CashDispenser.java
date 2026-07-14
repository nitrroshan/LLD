package chapter36;

/**
 * Validates a withdrawal amount and drives the denomination chain. Runs a
 * non-mutating canDispense() check first, so it never pays out partial cash.
 */
public class CashDispenser {
    private final DenominationHandler chain;

    public CashDispenser(DenominationHandler chain) {
        this.chain = chain;
    }

    public boolean dispense(int amount) {
        if (amount <= 0 || amount % 10 != 0) {
            System.out.println("    Amount must be a positive multiple of $10");
            return false;
        }
        if (amount > chain.totalCash()) {
            System.out.println("    ATM has insufficient cash");
            return false;
        }
        if (!chain.canDispense(amount)) {
            System.out.println("    Cannot dispense $" + amount + " with available notes");
            return false;
        }
        chain.dispense(amount);
        return true;
    }
}
