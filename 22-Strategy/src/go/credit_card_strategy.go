package main

import "fmt"

// CreditCardStrategy is a Concrete Strategy — pays with a credit card.
type CreditCardStrategy struct {
	cardNumber string
}

func (c *CreditCardStrategy) Pay(amount float64) {
	masked := "****" + c.cardNumber[len(c.cardNumber)-4:]
	fmt.Printf("  Paid $%.2f with credit card %s\n", amount, masked)
}
