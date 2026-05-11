// Chapter 06 — Abstract Factory Pattern in Go
// Run: go run .

package main

import "fmt"

// Free function — client code that works through the factory interface.
// Equivalent to the buildUI() method in Java/C++ but as a free function
// since Go interfaces can't have default methods.
func BuildUI(factory UIFactory) {
	button := factory.CreateButton()
	checkbox := factory.CreateCheckbox()
	menu := factory.CreateMenu()

	fmt.Println("--- Rendering UI ---")
	button.Render()
	checkbox.Render()
	menu.Render()

	fmt.Println("--- Interacting ---")
	button.OnClick()
	checkbox.Toggle()
	menu.Select("File > Save")
}

func main() {
	fmt.Println("=== Windows UI ===")
	BuildUI(WindowsFactory{})

	fmt.Println("\n=== Mac UI ===")
	BuildUI(MacFactory{})

	fmt.Println("\n=== All platforms (interface polymorphism) ===")
	factories := []UIFactory{WindowsFactory{}, MacFactory{}}
	for _, f := range factories {
		BuildUI(f)
		fmt.Println()
	}
}
