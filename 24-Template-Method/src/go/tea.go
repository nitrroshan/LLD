package main

import "fmt"

// Tea fills in the varying steps; it embeds DefaultBeverage for the hook.
type Tea struct {
	DefaultBeverage
}

func (Tea) Brew()          { fmt.Println("  Steeping the tea") }
func (Tea) AddCondiments() { fmt.Println("  Adding lemon") }
