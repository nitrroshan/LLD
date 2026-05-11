package main

import "fmt"

type Circle struct {
	baseShape
	Radius int
}

func NewCircle(x, y int, color string, radius int) *Circle {
	return &Circle{
		baseShape: baseShape{X: x, Y: y, Color: color, Tags: []string{}},
		Radius:    radius,
	}
}

func (c *Circle) Clone() Shape {
	return &Circle{
		baseShape: baseShape{
			X:     c.X,
			Y:     c.Y,
			Color:  c.Color,
			Tags:   deepCopyTags(c.Tags), // deep copy the slice
		},
		Radius: c.Radius,
	}
}

func (c *Circle) String() string {
	return fmt.Sprintf("Circle [radius=%d (%d,%d) color=%s tags=%v]",
		c.Radius, c.X, c.Y, c.Color, c.Tags)
}
