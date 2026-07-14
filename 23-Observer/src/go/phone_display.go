package main

import "fmt"

// PhoneDisplay is a Concrete Observer — a phone app that shows the temperature.
type PhoneDisplay struct {
	name string
}

func NewPhoneDisplay(name string) *PhoneDisplay {
	return &PhoneDisplay{name: name}
}

func (p *PhoneDisplay) Update(temperature float64) {
	fmt.Printf("  [Phone %s] It's now %.1f°C\n", p.name, temperature)
}
