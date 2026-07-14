package main

import "fmt"

// Subsystem type — the motorized screen.
type Screen struct{}

func (s Screen) Up()   { fmt.Println("Screen going up") }
func (s Screen) Down() { fmt.Println("Screen going down") }
