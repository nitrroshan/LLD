package main

import "fmt"

// printAll works with ANY iterator — the whole point of the pattern.
func printAll(it Iterator) {
	for it.HasNext() {
		fmt.Printf("  %s\n", it.Next())
	}
}

func main() {
	fmt.Println("=== Iterator Pattern Demo (Go) ===")
	fmt.Println()

	playlist := &Playlist{}
	playlist.AddSong(NewSong("Bohemian Rhapsody", "Queen"))
	playlist.AddSong(NewSong("Hotel California", "Eagles"))
	playlist.AddSong(NewSong("Stairway to Heaven", "Led Zeppelin"))

	fmt.Println("Forward:")
	printAll(playlist.Iterator())

	fmt.Println("\nReverse:")
	printAll(playlist.ReverseIterator())

	fmt.Println("\nTwo independent cursors:")
	a := playlist.Iterator()
	b := playlist.Iterator()
	fmt.Printf("  a.Next(): %s\n", a.Next())
	fmt.Printf("  a.Next(): %s\n", a.Next())
	fmt.Printf("  b.Next(): %s   (b is unaffected by a)\n", b.Next())
}
