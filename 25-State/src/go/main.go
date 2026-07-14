package main

import "fmt"

func main() {
	fmt.Println("=== State Pattern Demo (Go) ===")
	fmt.Println()

	machine := NewGumballMachine(2)
	fmt.Println(machine.Status())

	fmt.Println("\nBuy first gumball:")
	machine.InsertQuarter()
	machine.TurnCrank()
	fmt.Println(machine.Status())

	fmt.Println("\nBuy second gumball (empties the machine):")
	machine.InsertQuarter()
	machine.TurnCrank()
	fmt.Println(machine.Status())

	fmt.Println("\nTry to buy when sold out:")
	machine.InsertQuarter()
	machine.TurnCrank()

	fmt.Println("\nSame actions behaved differently in each state —")
	fmt.Println("no conditionals, just the current State object.")
}
