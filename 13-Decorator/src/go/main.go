package main

import "fmt"

func printCoffee(label string, c Coffee) {
	fmt.Printf("  %-15s %s — $%.2f\n", label+":", c.GetDescription(), c.GetCost())
}

func main() {
	fmt.Println("=== Decorator Pattern Demo (Go) ===")
	fmt.Println()

	// 1. Plain espresso
	printCoffee("Plain", Espresso{})

	// 2. Espresso + Milk
	printCoffee("With milk", WithMilk(Espresso{}))

	// 3. Stacked: Espresso + Milk + Whip + Caramel
	loaded := WithCaramel(WithWhip(WithMilk(Espresso{})))
	printCoffee("Loaded", loaded)

	// 4. Latte + Whip
	printCoffee("Latte+Whip", WithWhip(Latte{}))

	// 5. Double milk
	printCoffee("Double milk", WithMilk(WithMilk(Espresso{})))

	// 6. Dynamic decoration
	fmt.Println()
	fmt.Println("--- Dynamic Decoration ---")
	var order Coffee = Latte{}
	fmt.Printf("  Start:     %s — $%.2f\n", order.GetDescription(), order.GetCost())

	order = WithMilk(order)
	fmt.Printf("  + Milk:    %s — $%.2f\n", order.GetDescription(), order.GetCost())

	order = WithCaramel(order)
	fmt.Printf("  + Caramel: %s — $%.2f\n", order.GetDescription(), order.GetCost())
}
