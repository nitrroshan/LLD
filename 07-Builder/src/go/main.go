package main

import "fmt"

func main() {
	fmt.Println("=== Builder Pattern Demo ===")
	fmt.Println()

	// 1. Build a custom house step by step
	customHouse := NewHouseBuilder().
		Rooms(4).Floors(2).
		Garage().Pool().
		RoofType("tile").
		Build()
	fmt.Println("Custom: ", customHouse)

	// 2. Use the Director for pre-defined configurations
	director := HouseDirector{}

	luxury := director.BuildLuxuryHouse()
	fmt.Println("Luxury: ", luxury)

	simple := director.BuildSimpleHouse()
	fmt.Println("Simple: ", simple)

	family := director.BuildFamilyHouse()
	fmt.Println("Family: ", family)

	// 3. Minimal house — only defaults
	minimal := NewHouseBuilder().Build()
	fmt.Println("Minimal:", minimal)
}
