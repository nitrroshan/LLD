package main

import "fmt"

// Composition target: Library owns Books.
// Association source: Book knows its Author (pointer = doesn't own).

type Book struct {
	Title  string
	ISBN   string
	Author *Author // Association: knows author, doesn't own
}

func NewBook(title, isbn string, author *Author) *Book {
	return &Book{Title: title, ISBN: isbn, Author: author}
}

func (b *Book) DisplayInfo() {
	fmt.Printf("[Book] %s by %s (ISBN: %s)\n", b.Title, b.Author.Name, b.ISBN)
}
