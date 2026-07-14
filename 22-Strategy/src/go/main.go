package main

import "fmt"

func main() {
	fmt.Println("=== Strategy Pattern Demo (Go) ===")
	fmt.Println()

	cart := &ShoppingCart{}
	cart.AddItem("Keyboard", 49.99)
	cart.AddItem("Mouse", 25.50)

	// Choose a strategy at runtime
	fmt.Println("\nCheckout with credit card:")
	cart.SetPaymentStrategy(&CreditCardStrategy{cardNumber: "1234567812345678"})
	cart.Checkout()

	cart.AddItem("Monitor", 199.00)
	fmt.Println("\nCheckout with PayPal:")
	cart.SetPaymentStrategy(&PayPalStrategy{email: "shopper@example.com"})
	cart.Checkout()

	// A strategy can also be a plain function via PayFunc — no struct needed
	cart.AddItem("Cable", 9.99)
	fmt.Println("\nCheckout with a function strategy (Apple Pay):")
	cart.SetPaymentStrategy(PayFunc(func(amount float64) {
		fmt.Printf("  Paid $%.2f with Apple Pay\n", amount)
	}))
	cart.Checkout()
}
