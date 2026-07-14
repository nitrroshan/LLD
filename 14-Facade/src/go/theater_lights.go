package main

import "fmt"

// Subsystem type — the dimmable theater lights.
type TheaterLights struct{}

func (t TheaterLights) On()          { fmt.Println("Theater lights on") }
func (t TheaterLights) Dim(level int) { fmt.Printf("Theater lights dimming to %d%%\n", level) }
