#include <iostream>
#include <memory>
#include <vector>
#include "PurchaseRequest.h"
#include "Approver.h"
#include "TeamLead.h"
#include "Manager.h"
#include "Director.h"

int main() {
    std::cout << "=== Chain of Responsibility Demo (C++) ===\n\n";

    // Build the chain: Team Lead -> Manager -> Director.
    // The head owns the manager, which owns the director.
    auto team_lead = std::make_unique<TeamLead>();
    team_lead->set_next(std::make_unique<Manager>())
             ->set_next(std::make_unique<Director>());

    std::vector<PurchaseRequest> requests = {
        {800, "Office chairs"},      // Team Lead
        {3500, "Team offsite"},      // Manager
        {15000, "Server hardware"},  // Director
        {50000, "New data center"},  // nobody
    };

    for (const auto& request : requests) {
        std::cout << "Request: $" << request.amount() << " for " << request.purpose() << "\n";
        team_lead->handle(request);
        std::cout << "\n";
    }

    std::cout << "The client submits every request to the same head handler\n";
    std::cout << "and never needs to know who has the authority to approve it.\n";

    return 0;
}
