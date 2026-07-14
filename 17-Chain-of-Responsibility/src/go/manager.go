package main

import "fmt"

type Manager struct {
	BaseApprover
}

func (m *Manager) Handle(request PurchaseRequest) {
	if request.Amount <= 5000 {
		fmt.Printf("  Manager approved $%.2f for %s\n", request.Amount, request.Purpose)
	} else {
		m.passToNext(request)
	}
}
