package main

import "fmt"

// Light is the Receiver — it knows how to perform the real work.
type Light struct {
	location string
}

func NewLight(location string) *Light {
	return &Light{location: location}
}

func (l *Light) On() {
	fmt.Printf("  %s light is ON\n", l.location)
}

func (l *Light) Off() {
	fmt.Printf("  %s light is OFF\n", l.location)
}
