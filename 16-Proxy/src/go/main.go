package main

import "fmt"

func main() {
	fmt.Println("=== Proxy Pattern Demo (Virtual / Lazy Loading, Go) ===")
	fmt.Println()

	// Creating the proxies is cheap — no disk load happens here
	fmt.Println("Creating image proxies (no loading expected):")
	var photo1 Image = NewProxyImage("vacation.jpg")
	var photo2 Image = NewProxyImage("portrait.jpg")

	// The heavy load happens only when Display() is first called
	fmt.Println("\nFirst display of photo1 (triggers load):")
	photo1.Display()

	fmt.Println("\nSecond display of photo1 (already loaded, no reload):")
	photo1.Display()

	fmt.Println("\nphoto2 was never displayed — so it was never loaded.")
	fmt.Println("That is the point of a virtual proxy: pay the cost only if used.")
	_ = photo2
}
