package main

import "fmt"

type Rectangle struct {
	Width  float64
	Height float64
}

func (r *Rectangle) Draw() {
	fmt.Printf("Drawing Rectangle (%.1f x %.1f)\n", r.Width, r.Height)
}

func (r *Rectangle) Area() float64 {
	return r.Width * r.Height
}
