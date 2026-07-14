package main

import "fmt"

func main() {
	fmt.Println("=== Memento Pattern Demo (Go) ===")
	fmt.Println()

	editor := &TextEditor{}
	history := &History{}

	editor.Type("Hello")
	history.Push(editor.Save("after Hello"))
	fmt.Printf("Content: %q\n", editor.Content())

	editor.Type(", World")
	history.Push(editor.Save("after World"))
	fmt.Printf("Content: %q\n", editor.Content())

	editor.Type("!!!")
	fmt.Printf("Content: %q  (not yet saved)\n", editor.Content())

	fmt.Println("\nUndo:")
	editor.Restore(history.Pop())
	fmt.Printf("Content: %q\n", editor.Content())

	fmt.Println("\nUndo again:")
	editor.Restore(history.Pop())
	fmt.Printf("Content: %q\n", editor.Content())

	fmt.Println("\nThe editor's content stayed unexported the whole time —")
	fmt.Println("the History caretaker only held opaque snapshots.")
}
