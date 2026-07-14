package main

import "fmt"

type Director struct {
	BaseApprover
}

func (d *Director) Handle(request PurchaseRequest) {
	if request.Amount <= 20000 {
		fmt.Printf("  Director approved $%.2f for %s\n", request.Amount, request.Purpose)
	} else {
		d.passToNext(request)
	}
}
