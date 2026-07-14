package main

import "fmt"

// Subsystem type — the video projector.
type Projector struct{}

func (p Projector) On()              { fmt.Println("Projector on") }
func (p Projector) Off()             { fmt.Println("Projector off") }
func (p Projector) WideScreenMode()  { fmt.Println("Projector in widescreen mode (16:9)") }
