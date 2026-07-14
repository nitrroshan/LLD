package main

import "fmt"

// Subsystem type — the DVD player.
type DvdPlayer struct{}

func (d DvdPlayer) On()               { fmt.Println("DVD player on") }
func (d DvdPlayer) Off()              { fmt.Println("DVD player off") }
func (d DvdPlayer) Play(movie string) { fmt.Printf("Playing %q\n", movie) }
func (d DvdPlayer) Stop()             { fmt.Println("Stopping playback") }
