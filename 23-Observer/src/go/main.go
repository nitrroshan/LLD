package main

import "fmt"

func main() {
	fmt.Println("=== Observer Pattern Demo (Go) ===")
	fmt.Println()

	station := &WeatherStation{}

	alicePhone := NewPhoneDisplay("Alice")
	bobPhone := NewPhoneDisplay("Bob")
	window := &WindowDisplay{}

	// Subscribe observers
	station.RegisterObserver(alicePhone)
	station.RegisterObserver(bobPhone)
	station.RegisterObserver(window)

	// One change → everyone is notified automatically
	station.SetTemperature(22.5)

	fmt.Println()
	station.SetTemperature(28.0)

	// Unsubscribe at runtime — Bob stops receiving updates
	fmt.Println("\nBob unsubscribes...")
	station.RemoveObserver(bobPhone)

	fmt.Println()
	station.SetTemperature(19.0)

	fmt.Println("\nThe station never referenced a concrete display —")
	fmt.Println("it only pushed updates to the Observer list.")
}
