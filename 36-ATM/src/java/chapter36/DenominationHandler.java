package chapter36;

/**
 * Chain of Responsibility — one handler per note denomination. Each handler
 * takes as many of its note as it can and forwards the remainder to the next.
 */
public abstract class DenominationHandler {
    protected final int denomination;
    protected int availableNotes;
    protected DenominationHandler next;

    protected DenominationHandler(int denomination, int availableNotes) {
        this.denomination = denomination;
        this.availableNotes = availableNotes;
    }

    /** Wire the next handler in the chain; returns it for fluent chaining. */
    public DenominationHandler setNext(DenominationHandler next) {
        this.next = next;
        return next;
    }

    /** Total cash held from this handler onward. */
    public int totalCash() {
        int mine = denomination * availableNotes;
        return next == null ? mine : mine + next.totalCash();
    }

    /** Simulate greedily WITHOUT mutating counts — can this amount be made exactly? */
    public boolean canDispense(int amount) {
        int use = Math.min(amount / denomination, availableNotes);
        int remaining = amount - use * denomination;
        if (remaining == 0) {
            return true;
        }
        return next != null && next.canDispense(remaining);
    }

    /** Actually dispense greedily, mutating counts. Assumes canDispense was true. */
    public void dispense(int amount) {
        int use = Math.min(amount / denomination, availableNotes);
        if (use > 0) {
            availableNotes -= use;
            System.out.println("    Dispensing " + use + " x $" + denomination);
        }
        int remaining = amount - use * denomination;
        if (remaining > 0 && next != null) {
            next.dispense(remaining);
        }
    }
}
