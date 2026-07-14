package main

import "fmt"

// TreeFactory creates and caches shared *TreeType flyweights.
// The same intrinsic combination always returns the SAME pointer.
type TreeFactory struct {
	cache map[string]*TreeType
}

func NewTreeFactory() *TreeFactory {
	return &TreeFactory{cache: make(map[string]*TreeType)}
}

func (f *TreeFactory) GetTreeType(name, color, texture string) *TreeType {
	key := name + "-" + color + "-" + texture
	if t, ok := f.cache[key]; ok {
		return t
	}
	fmt.Printf("  [Factory] Creating new TreeType: %s\n", key)
	t := &TreeType{name: name, color: color, texture: texture}
	f.cache[key] = t
	return t
}

func (f *TreeFactory) DistinctTypeCount() int { return len(f.cache) }
