// Chapter 03 — SOLID Principles in Go
// Run: go run .

package main

import "fmt"

func main() {
	fmt.Println("=== S — Single Responsibility ===")
	inv := &Invoice{Product: "Keyboard", Quantity: 2, PricePerUnit: 49.99}
	InvoicePrinter{}.Print(inv)
	InvoiceRepository{}.Save(inv)

	fmt.Println("\n=== O — Open/Closed ===")
	amount := 1000.0
	fmt.Printf("Regular:  $%.0f\n", CalculateDiscount(RegularDiscount{}, amount))
	fmt.Printf("Premium:  $%.0f\n", CalculateDiscount(PremiumDiscount{}, amount))
	fmt.Printf("VIP:      $%.0f\n", CalculateDiscount(VIPDiscount{}, amount))
	fmt.Printf("Employee: $%.0f\n", CalculateDiscount(EmployeeDiscount{}, amount))

	fmt.Println("\n=== L — Liskov Substitution ===")
	MakeFly(Sparrow{})
	// MakeFly(PenguinGood{})  // won't compile — PenguinGood doesn't satisfy Flyable
	PenguinGood{}.Swim()

	fmt.Println("\n=== I — Interface Segregation ===")
	SimplePrinterISP{}.Print("report.pdf")
	aio := AllInOnePrinter{}
	aio.Print("report.pdf")
	aio.Scan("photo.jpg")
	aio.Fax("contract.pdf")

	fmt.Println("\n=== D — Dependency Inversion ===")
	(&OrderService{DB: MySQLDB{}}).PlaceOrder("Laptop")
	(&OrderService{DB: PostgreSQLDB{}}).PlaceOrder("Phone")
	(&OrderService{DB: InMemoryDB{}}).PlaceOrder("Tablet")
}
