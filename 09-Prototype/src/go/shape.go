package main

import "fmt"

type Shape interface {
	Clone() Shape
	MoveTo(x, y int)
	AddTag(tag string)
	String() string
}

type baseShape struct {
	X, Y  int
	Color string
	Tags  []string
}

func (b *baseShape) MoveTo(x, y int) {
	b.X = x
	b.Y = y
}

func (b *baseShape) AddTag(tag string) {
	b.Tags = append(b.Tags, tag)
}

// deepCopyTags creates a new slice with copied elements
func deepCopyTags(tags []string) []string {
	if tags == nil {
		return nil
	}
	copied := make([]string, len(tags))
	copy(copied, tags)
	return copied
}
