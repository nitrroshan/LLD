package main

import "fmt"

// ShoppingCart is the Context — it holds a payment strategy and delegates
// checkout to it. The strategy can be swapped at runtime.
type ShoppingCart struct {
	total    float64
	strategy PaymentStrategy
}

func (s *ShoppingCart) AddItem(name string, price float64) {
	s.total += price
	fmt.Printf("  + %s ($%.2f)\n", name, price)
}

func (s *ShoppingCart) SetPaymentStrategy(strategy PaymentStrategy) {
	s.strategy = strategy
}

func (s *ShoppingCart) Checkout() {
	if s.strategy == nil {
		fmt.Println("  No payment method selected!")
		return
	}
	s.strategy.Pay(s.total)
	s.total = 0
}
