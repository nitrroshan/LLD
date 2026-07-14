package chapter17;

public class Manager extends Approver {
    public Manager() {
        super("Manager", 5000);
    }

    @Override
    protected void approve(PurchaseRequest request) {
        System.out.printf("  %s approved $%.2f for %s%n",
                name, request.getAmount(), request.getPurpose());
    }
}
