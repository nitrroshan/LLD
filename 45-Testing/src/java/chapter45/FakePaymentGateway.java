package chapter45;

/**
 * A test double for PaymentGateway: a STUB (returns a canned result) that is also
 * a SPY (records how it was called), so tests can verify the interaction.
 */
public class FakePaymentGateway implements PaymentGateway {
    private final boolean result;
    public int chargeCount = 0;
    public double lastAmount = -1;

    public FakePaymentGateway(boolean result) {
        this.result = result;   // stubbed return value
    }

    @Override
    public boolean charge(double amount) {
        chargeCount++;          // spy: record the call
        lastAmount = amount;
        return result;          // stub: canned answer, no real network
    }
}
