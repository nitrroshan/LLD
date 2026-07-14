package main

import "fmt"

func main() {
	fmt.Println("=== Composite Pattern Demo (Go) ===")
	fmt.Println()

	// Build the tree
	root := NewDirectory("project")
	root.Add(NewFile("README.md", 150))
	root.Add(NewFile(".gitignore", 30))

	src := NewDirectory("src")
	src.Add(NewFile("Main.java", 500))
	src.Add(NewFile("Utils.java", 300))
	src.Add(NewFile("Config.java", 200))

	test := NewDirectory("test")
	test.Add(NewFile("MainTest.java", 400))
	test.Add(NewFile("UtilsTest.java", 250))
	src.Add(test)

	root.Add(src)

	docs := NewDirectory("docs")
	docs.Add(NewFile("guide.md", 800))
	docs.Add(NewFile("api.md", 600))
	root.Add(docs)

	// 1. Print the tree
	fmt.Println("--- File System Tree ---")
	root.Print("")
	fmt.Println()

	// 2. Uniform treatment
	fmt.Println("--- Sizes ---")
	fmt.Printf("root total: %d bytes\n", root.GetSize())
	fmt.Println()

	// 3. Iterate children — no type switch needed
	fmt.Println("--- Direct children of root ---")
	for _, child := range root.GetChildren() {
		fmt.Printf("  %s -> %d bytes\n", child.GetName(), child.GetSize())
	}
}
