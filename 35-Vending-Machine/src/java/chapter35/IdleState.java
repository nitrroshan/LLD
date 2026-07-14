package chapter35;

/**
 * Idle — waiting for a product selection.
 */
public class IdleState implements VendingMachineState {
    private final VendingMachine machine;

    public IdleState(VendingMachine machine) {
        this.machine = machine;
    }

    @Override
    public void selectProduct(String code) {
        Product product = machine.getInventory().getProduct(code);
        if (product == null) {
            System.out.println("  No product at slot " + code);
            return;
        }
        if (!machine.getInventory().isInStock(code)) {
            System.out.println("  " + product.getName() + " is out of stock");
            return;
        }
        machine.setSelectedCode(code);
        System.out.printf("  Selected %s ($%.2f). Insert coins or pay by card.%n",
                product.getName(), product.getPriceCents() / 100.0);
        machine.setState(machine.getAwaitingPaymentState());
    }

    @Override
    public void insertCoin(Coin coin) {
        System.out.println("  Select a product first");
    }

    @Override
    public void payWith(PaymentStrategy strategy) {
        System.out.println("  Select a product first");
    }

    @Override
    public void cancel() {
        System.out.println("  Nothing to cancel");
    }

    @Override
    public String name() {
        return "IDLE";
    }
}
