package main

import "fmt"

// Coffee fills in the varying steps; it embeds DefaultBeverage for the hook.
type Coffee struct {
	DefaultBeverage
}

func (Coffee) Brew()          { fmt.Println("  Dripping coffee through filter") }
func (Coffee) AddCondiments() { fmt.Println("  Adding sugar and milk") }
