package main

import "fmt"

// Beverage is the interface of the VARYING steps. Go has no inheritance, so
// the template method is a free function (PrepareRecipe) that takes this
// interface and calls the steps in the fixed order.
type Beverage interface {
	Brew()
	AddCondiments()
	WantsCondiments() bool
}

// Invariant steps — shared by all beverages.
func boilWater() { fmt.Println("  Boiling water") }
func pourInCup() { fmt.Println("  Pouring into cup") }

// PrepareRecipe is the template method: the fixed skeleton and ordering.
func PrepareRecipe(b Beverage) {
	boilWater()
	b.Brew()
	pourInCup()
	if b.WantsCondiments() {
		b.AddCondiments()
	}
}
