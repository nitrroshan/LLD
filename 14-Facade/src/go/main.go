package main

import "fmt"

func main() {
	fmt.Println("=== Facade Pattern Demo (Go) ===")
	fmt.Println()

	// Build the subsystem components
	projector := Projector{}
	screen := Screen{}
	amplifier := Amplifier{}
	lights := TheaterLights{}
	dvdPlayer := DvdPlayer{}

	// Wrap them in a facade
	theater := NewHomeTheaterFacade(projector, screen, amplifier, lights, dvdPlayer)

	// Two simple calls instead of orchestrating 8 subsystem steps
	theater.WatchMovie("Inception")

	fmt.Println()
	theater.EndMovie()

	// The subsystem is still accessible for advanced use
	fmt.Println()
	fmt.Println("--- Direct subsystem access (advanced) ---")
	projector.On()
	projector.WideScreenMode()
	projector.Off()
}
