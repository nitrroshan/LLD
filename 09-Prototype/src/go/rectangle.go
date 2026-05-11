package main

import "fmt"

type Rectangle struct {
	baseShape
	Width  int
	Height int
}

func NewRectangle(x, y int, color string, width, height int) *Rectangle {
	return &Rectangle{
		baseShape: baseShape{X: x, Y: y, Color: color, Tags: []string{}},
		Width:     width,
		Height:    height,
	}
}

func (r *Rectangle) Clone() Shape {
	return &Rectangle{
		baseShape: baseShape{
			X:     r.X,
			Y:     r.Y,
			Color:  r.Color,
			Tags:   deepCopyTags(r.Tags),
		},
		Width:  r.Width,
		Height: r.Height,
	}
}

func (r *Rectangle) String() string {
	return fmt.Sprintf("Rectangle [%dx%d (%d,%d) color=%s tags=%v]",
		r.Width, r.Height, r.X, r.Y, r.Color, r.Tags)
}
