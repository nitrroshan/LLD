package main

import "fmt"

// TreeType is the Flyweight — stores ONLY intrinsic (shared) state.
// Fields are unexported and never mutated, so it is safe to share.
// Extrinsic state (x, y) is passed IN via Draw().
type TreeType struct {
	name    string
	color   string
	texture string
}

func (t *TreeType) Draw(x, y int) {
	fmt.Printf("  Drawing %s (%s, texture=%s) at (%d, %d)\n",
		t.name, t.color, t.texture, x, y)
}

func (t *TreeType) Name() string { return t.name }
