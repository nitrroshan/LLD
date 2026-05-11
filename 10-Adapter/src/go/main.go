package main

import "fmt"

func processOrder(processor PaymentProcessor, amount float64, currency string) {
	success := processor.ProcessPayment(amount, currency)
	result := "failed"
	if success {
		result = "succeeded"
	}
	fmt.Printf("  Payment %s\n\n", result)
}

func refundOrder(processor PaymentProcessor, transactionId string) {
	success := processor.Refund(transactionId)
	result := "failed"
	if success {
		result = "succeeded"
	}
	fmt.Printf("  Refund %s\n\n", result)
}

func main() {
	fmt.Println("=== Adapter Pattern Demo (Go) ===")
	fmt.Println()

	stripe := NewStripeAdapter(&StripeApi{}, "sk_test_abc123")
	paypal := NewPayPalAdapter(&PayPalApi{})

	// 1. Process payments through the same interface
	fmt.Println("--- Process Payments ---")
	processOrder(stripe, 49.99, "USD")
	processOrder(paypal, 29.99, "EUR")

	// 2. Refunds
	fmt.Println("--- Refund Payments ---")
	refundOrder(stripe, "ch_12345")
	refundOrder(paypal, "PAY-67890")

	// 3. Swap implementations — client code doesn't change
	fmt.Println("--- Swap Implementation ---")
	var processor PaymentProcessor = stripe
	processOrder(processor, 99.99, "USD")

	processor = paypal
	processOrder(processor, 99.99, "USD")
}
