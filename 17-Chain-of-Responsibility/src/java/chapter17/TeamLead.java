package chapter17;

public class TeamLead extends Approver {
    public TeamLead() {
        super("Team Lead", 1000);
    }

    @Override
    protected void approve(PurchaseRequest request) {
        System.out.printf("  %s approved $%.2f for %s%n",
                name, request.getAmount(), request.getPurpose());
    }
}
