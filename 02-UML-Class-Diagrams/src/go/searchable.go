package main

// Realization: Searchable interface (implemented implicitly by Library).

type Searchable interface {
	Search(title string) *Book
	SearchByAuthor(authorName string) []*Book
}
