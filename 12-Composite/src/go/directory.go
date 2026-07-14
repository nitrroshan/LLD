package main

import "fmt"

// Composite — a directory that contains files and/or other directories
type Directory struct {
	Name     string
	children []FileSystemNode
}

func NewDirectory(name string) *Directory {
	return &Directory{Name: name}
}

func (d *Directory) Add(node FileSystemNode) {
	d.children = append(d.children, node)
}

func (d *Directory) GetChildren() []FileSystemNode {
	return d.children
}

func (d *Directory) GetName() string { return d.Name }

func (d *Directory) GetSize() int {
	total := 0
	for _, child := range d.children {
		total += child.GetSize()
	}
	return total
}

func (d *Directory) Print(indent string) {
	fmt.Printf("%sD %s/ (%d bytes)\n", indent, d.Name, d.GetSize())
	for _, child := range d.children {
		child.Print(indent + "  ")
	}
}
