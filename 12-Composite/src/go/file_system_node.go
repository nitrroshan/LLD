package main

// Component interface
type FileSystemNode interface {
	GetName() string
	GetSize() int
	Print(indent string)
}
