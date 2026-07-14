package main

import "fmt"

func main() {
	fmt.Println("=== Chain of Responsibility Demo (Go) ===")
	fmt.Println()

	// Build the chain: Team Lead -> Manager -> Director
	teamLead := &TeamLead{}
	teamLead.SetNext(&Manager{}).SetNext(&Director{})

	requests := []PurchaseRequest{
		{Amount: 800, Purpose: "Office chairs"},     // Team Lead
		{Amount: 3500, Purpose: "Team offsite"},     // Manager
		{Amount: 15000, Purpose: "Server hardware"}, // Director
		{Amount: 50000, Purpose: "New data center"}, // nobody
	}

	for _, request := range requests {
		fmt.Printf("Request: $%.2f for %s\n", request.Amount, request.Purpose)
		teamLead.Handle(request)
		fmt.Println()
	}

	fmt.Println("The client submits every request to the same head handler")
	fmt.Println("and never needs to know who has the authority to approve it.")
}
