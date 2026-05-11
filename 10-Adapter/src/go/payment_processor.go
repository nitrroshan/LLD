package main

type PaymentProcessor interface {
	ProcessPayment(amount float64, currency string) bool
	Refund(transactionId string) bool
}
