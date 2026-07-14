package chapter17;

public class Director extends Approver {
    public Director() {
        super("Director", 20000);
    }

    @Override
    protected void approve(PurchaseRequest request) {
        System.out.printf("  %s approved $%.2f for %s%n",
                name, request.getAmount(), request.getPurpose());
    }
}
