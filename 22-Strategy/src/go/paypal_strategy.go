package main

import "fmt"

// PayPalStrategy is a Concrete Strategy — pays via PayPal.
type PayPalStrategy struct {
	email string
}

func (p *PayPalStrategy) Pay(amount float64) {
	fmt.Printf("  Paid $%.2f via PayPal account %s\n", amount, p.email)
}
