package main

import "fmt"

type ShapeRegistry struct {
	prototypes map[string]Shape
}

func NewShapeRegistry() *ShapeRegistry {
	return &ShapeRegistry{prototypes: make(map[string]Shape)}
}

func (r *ShapeRegistry) Register(key string, shape Shape) {
	r.prototypes[key] = shape
}

func (r *ShapeRegistry) Get(key string) Shape {
	prototype, ok := r.prototypes[key]
	if !ok {
		panic(fmt.Sprintf("Unknown prototype: %s", key))
	}
	return prototype.Clone() // return a CLONE, not the original
}

func (r *ShapeRegistry) Contains(key string) bool {
	_, ok := r.prototypes[key]
	return ok
}

func (r *ShapeRegistry) Size() int {
	return len(r.prototypes)
}
