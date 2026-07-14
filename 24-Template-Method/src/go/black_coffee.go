package main

import "fmt"

// BlackCoffee overrides the WantsCondiments hook to skip the condiment step.
type BlackCoffee struct {
	DefaultBeverage
}

func (BlackCoffee) Brew()             { fmt.Println("  Dripping coffee through filter") }
func (BlackCoffee) AddCondiments()    {}
func (BlackCoffee) WantsCondiments() bool { return false }
