package main

import (
	"fmt"
	"math"
)

type Circle struct {
	Radius float64
}

func (c *Circle) Draw() {
	fmt.Printf("Drawing Circle with radius %.1f\n", c.Radius)
}

func (c *Circle) Area() float64 {
	return math.Pi * c.Radius * c.Radius
}
