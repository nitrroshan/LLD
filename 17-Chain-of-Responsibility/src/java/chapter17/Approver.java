package chapter17;

/**
 * Handler — declares the interface for handling requests and holds a
 * reference to the next handler in the chain. Provides the forwarding logic;
 * subclasses only decide whether they can approve.
 */
public abstract class Approver {
    protected Approver next;
    protected final String name;
    protected final double limit;

    protected Approver(String name, double limit) {
        this.name = name;
        this.limit = limit;
    }

    /** Wire the next handler; returns it so calls can be chained fluently. */
    public Approver setNext(Approver next) {
        this.next = next;
        return next;
    }

    public void handle(PurchaseRequest request) {
        if (request.getAmount() <= limit) {
            approve(request);
        } else if (next != null) {
            next.handle(request);
        } else {
            System.out.printf("  Request for $%.2f (%s) could not be approved by anyone.%n",
                    request.getAmount(), request.getPurpose());
        }
    }

    protected abstract void approve(PurchaseRequest request);
}
