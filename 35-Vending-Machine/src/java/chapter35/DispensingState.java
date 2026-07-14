package chapter35;

/**
 * Dispensing — releases the item, returns change, and resets to Idle.
 */
public class DispensingState implements VendingMachineState {
    private final VendingMachine machine;

    public DispensingState(VendingMachine machine) {
        this.machine = machine;
    }

    @Override
    public void dispense() {
        Product product = machine.getSelectedProduct();
        machine.getInventory().reduceStock(product.getCode());
        int change = machine.getBalance() - product.getPriceCents();
        System.out.println("  Dispensing " + product.getName());
        if (change > 0) {
            System.out.printf("  Returning change $%.2f%n", change / 100.0);
        }
        machine.reset();
        machine.setState(machine.getIdleState());
    }

    @Override
    public void selectProduct(String code) {
        System.out.println("  Please wait, dispensing");
    }

    @Override
    public void insertCoin(Coin coin) {
        System.out.println("  Please wait, dispensing");
    }

    @Override
    public void payWith(PaymentStrategy strategy) {
        System.out.println("  Please wait, dispensing");
    }

    @Override
    public void cancel() {
        System.out.println("  Too late to cancel, dispensing");
    }

    @Override
    public String name() {
        return "DISPENSING";
    }
}
