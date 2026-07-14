package chapter17;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Chain of Responsibility Demo ===\n");

        // Build the chain: Team Lead -> Manager -> Director
        Approver teamLead = new TeamLead();
        Approver manager = new Manager();
        Approver director = new Director();
        teamLead.setNext(manager).setNext(director);

        // Fire requests at the head — the chain finds the right approver
        PurchaseRequest[] requests = {
            new PurchaseRequest(800, "Office chairs"),      // Team Lead
            new PurchaseRequest(3500, "Team offsite"),      // Manager
            new PurchaseRequest(15000, "Server hardware"),  // Director
            new PurchaseRequest(50000, "New data center"),  // nobody
        };

        for (PurchaseRequest request : requests) {
            System.out.printf("Request: $%.2f for %s%n", request.getAmount(), request.getPurpose());
            teamLead.handle(request);
            System.out.println();
        }

        System.out.println("The client submits every request to the same head handler");
        System.out.println("and never needs to know who has the authority to approve it.");
    }
}
