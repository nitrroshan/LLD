package main

import "fmt"

// WindowDisplay is a Concrete Observer — a dashboard that reacts to temperature.
type WindowDisplay struct{}

func (w *WindowDisplay) Update(temperature float64) {
	advice := "keep them closed"
	if temperature > 25 {
		advice = "open the windows"
	}
	fmt.Printf("  [Window] %.1f°C — %s\n", temperature, advice)
}
