package main

import "fmt"

func main() {
	fmt.Println("=== Prototype Pattern Demo (Go) ===")
	fmt.Println()

	// 1. Create originals
	originalCircle := NewCircle(0, 0, "red", 10)
	originalCircle.AddTag("template")
	originalCircle.AddTag("primary")

	originalRect := NewRectangle(0, 0, "blue", 100, 50)
	originalRect.AddTag("template")

	fmt.Println("--- Originals ---")
	fmt.Println("Original:", originalCircle)
	fmt.Println("Original:", originalRect)
	fmt.Println()

	// 2. Clone and customize
	fmt.Println("--- Clone & Customize ---")
	clone1 := originalCircle.Clone()
	clone1.MoveTo(10, 20)
	clone1.AddTag("clone-1")

	clone2 := originalCircle.Clone()
	clone2.MoveTo(30, 40)
	clone2.AddTag("clone-2")

	fmt.Println("Clone 1: ", clone1)
	fmt.Println("Clone 2: ", clone2)
	fmt.Println("Original:", originalCircle)
	fmt.Println("  ^ tags unchanged — deep copy worked!")
	fmt.Println()

	// 3. Polymorphic cloning — clone through interface
	fmt.Println("--- Polymorphic Cloning ---")
	var shapeRef Shape = originalCircle
	cloned := shapeRef.Clone()
	fmt.Println("Cloned via Shape ref:", cloned)
	fmt.Println()

	// 4. Prototype Registry
	fmt.Println("--- Prototype Registry ---")
	registry := NewShapeRegistry()
	registry.Register("red-circle", NewCircle(0, 0, "red", 10))
	registry.Register("blue-rect", NewRectangle(0, 0, "blue", 100, 50))

	s1 := registry.Get("red-circle")
	s2 := registry.Get("red-circle")
	s3 := registry.Get("blue-rect")

	s1.MoveTo(10, 10)
	s2.MoveTo(50, 50)
	s3.MoveTo(100, 100)

	fmt.Println("From registry:", s1)
	fmt.Println("From registry:", s2)
	fmt.Println("From registry:", s3)
	fmt.Println("Same object?", s1 == s2) // false
}
