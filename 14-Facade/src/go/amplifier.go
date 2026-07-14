package main

import "fmt"

// Subsystem type — the audio amplifier.
type Amplifier struct{}

func (a Amplifier) On()                { fmt.Println("Amplifier on") }
func (a Amplifier) Off()               { fmt.Println("Amplifier off") }
func (a Amplifier) SetVolume(level int) { fmt.Printf("Amplifier volume set to %d\n", level) }
