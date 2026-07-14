package main

import "fmt"

func main() {
	fmt.Println("=== Template Method Pattern Demo (Go) ===")
	fmt.Println()

	fmt.Println("Making tea:")
	PrepareRecipe(Tea{})

	fmt.Println("\nMaking coffee:")
	PrepareRecipe(Coffee{})

	fmt.Println("\nMaking black coffee (hook skips condiments):")
	PrepareRecipe(BlackCoffee{})

	fmt.Println("\nEvery beverage followed the SAME fixed sequence —")
	fmt.Println("only the brew and condiment steps varied.")
}
