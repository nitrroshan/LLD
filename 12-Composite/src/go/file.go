package main

import "fmt"

// Leaf — a file with a fixed size
type File struct {
	Name string
	Size int
}

func NewFile(name string, size int) *File {
	return &File{Name: name, Size: size}
}

func (f *File) GetName() string { return f.Name }
func (f *File) GetSize() int    { return f.Size }

func (f *File) Print(indent string) {
	fmt.Printf("%sF %s (%d bytes)\n", indent, f.Name, f.Size)
}
