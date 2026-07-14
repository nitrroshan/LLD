package main

// PaymentStrategy is the common interface for interchangeable payment
// algorithms.
type PaymentStrategy interface {
	Pay(amount float64)
}
