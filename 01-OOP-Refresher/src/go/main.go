// ============================================================
// Chapter 01 — OOP Refresher in Go
// Run: go run .   (from this directory)
//
// Structure mirrors Java: one file per type
//   animal.go, dog.go, cat.go, bank_account.go,
//   drawable.go, circle.go, rectangle.go, calculator.go
//
// NOTE: Go has NO classes, NO inheritance, NO method overloading.
// Instead: structs + interfaces + embedding (composition).
// ============================================================

package main

import "fmt"

func main() {
	fmt.Println("=== ENCAPSULATION ===")
	account := NewBankAccount("Alice", 1000)
	account.Deposit(500)
	account.Withdraw(200)
	account.Withdraw(5000)
	fmt.Printf("Balance: %.1f\n", account.GetBalance())

	fmt.Println("\n=== INTERFACES & POLYMORPHISM ===")
	animals := []Animal{
		&Dog{Name: "Buddy", Breed: "Golden Retriever"},
		&Cat{Name: "Whiskers"},
		&Dog{Name: "Rex", Breed: "German Shepherd"},
	}

	for _, animal := range animals {
		animal.Eat()
		animal.MakeSound()
		fmt.Println()
	}

	fmt.Println("=== ABSTRACTION (Interfaces) ===")
	drawables := []Drawable{
		&Circle{Radius: 5},
		&Rectangle{Width: 4, Height: 6},
	}

	for _, d := range drawables {
		d.Draw()
		fmt.Printf("Area: %.2f\n\n", d.Area())
	}

	fmt.Println("=== NO OVERLOADING — Use different names ===")
	fmt.Printf("AddInt(2, 3)        = %d\n", AddInt(2, 3))
	fmt.Printf("AddFloat(2.5, 3.5)  = %.1f\n", AddFloat(2.5, 3.5))
	fmt.Printf("AddThree(1, 2, 3)   = %d\n", AddThree(1, 2, 3))
}
