package chapter35;

/**
 * AwaitingPayment — accepting money (coins via the chain, or an instant payment
 * strategy) until the price is met, then transitioning to dispensing.
 */
public class AwaitingPaymentState implements VendingMachineState {
    private final VendingMachine machine;

    public AwaitingPaymentState(VendingMachine machine) {
        this.machine = machine;
    }

    @Override
    public void selectProduct(String code) {
        System.out.println("  Finish paying or cancel the current selection first");
    }

    @Override
    public void insertCoin(Coin coin) {
        int accepted = machine.getCoinChain().handle(coin);   // Chain of Responsibility
        if (accepted == 0) {
            System.out.println("  Rejected coin: " + coin + " (returned)");
            return;
        }
        machine.addBalance(accepted);
        Product product = machine.getSelectedProduct();
        System.out.printf("  Inserted %s. Balance $%.2f / $%.2f%n",
                coin, machine.getBalance() / 100.0, product.getPriceCents() / 100.0);
        dispenseIfFunded();
    }

    @Override
    public void payWith(PaymentStrategy strategy) {
        Product product = machine.getSelectedProduct();
        int due = product.getPriceCents() - machine.getBalance();
        if (strategy.pay(due)) {
            machine.addBalance(due);
            dispenseIfFunded();
        } else {
            System.out.println("  Payment failed");
        }
    }

    @Override
    public void cancel() {
        int refund = machine.getBalance();
        if (refund > 0) {
            System.out.printf("  Refunding $%.2f%n", refund / 100.0);
        }
        machine.reset();
        machine.setState(machine.getIdleState());
        System.out.println("  Cancelled");
    }

    private void dispenseIfFunded() {
        Product product = machine.getSelectedProduct();
        if (machine.getBalance() >= product.getPriceCents()) {
            machine.setState(machine.getDispensingState());
            machine.getDispensingState().dispense();
        }
    }

    @Override
    public String name() {
        return "AWAITING_PAYMENT";
    }
}
