mod purchase_request;
mod approver;
mod team_lead;
mod manager;
mod director;

use approver::Approver;
use purchase_request::PurchaseRequest;
use team_lead::TeamLead;
use manager::Manager;
use director::Director;

fn main() {
    println!("=== Chain of Responsibility Demo (Rust) ===\n");

    // Build the chain from the tail toward the head: Team Lead -> Manager -> Director.
    // Ownership makes the chain a nicely nested structure.
    let chain = TeamLead::new().set_next(
        Box::new(Manager::new().set_next(
            Box::new(Director::new()),
        )),
    );

    let requests = [
        PurchaseRequest::new(800.0, "Office chairs"),     // Team Lead
        PurchaseRequest::new(3500.0, "Team offsite"),     // Manager
        PurchaseRequest::new(15000.0, "Server hardware"), // Director
        PurchaseRequest::new(50000.0, "New data center"), // nobody
    ];

    for request in &requests {
        println!("Request: ${:.2} for {}", request.amount, request.purpose);
        chain.handle(request);
        println!();
    }

    println!("The client submits every request to the same head handler");
    println!("and never needs to know who has the authority to approve it.");
}
