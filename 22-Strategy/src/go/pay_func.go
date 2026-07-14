package main

// PayFunc adapts a plain function into a PaymentStrategy. This is the
// idiomatic Go "strategy as a function" form — no dedicated struct needed.
type PayFunc func(amount float64)

func (f PayFunc) Pay(amount float64) {
	f(amount)
}
