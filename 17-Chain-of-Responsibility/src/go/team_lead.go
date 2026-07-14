package main

import "fmt"

type TeamLead struct {
	BaseApprover
}

func (t *TeamLead) Handle(request PurchaseRequest) {
	if request.Amount <= 1000 {
		fmt.Printf("  Team Lead approved $%.2f for %s\n", request.Amount, request.Purpose)
	} else {
		t.passToNext(request)
	}
}
