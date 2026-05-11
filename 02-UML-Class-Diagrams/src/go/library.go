package main

import (
	"fmt"
	"strings"
)

// Composition: Library owns Books (stored in slice).
// Aggregation: Library has Members (pointers — doesn't own lifecycle).
// Realization: Library satisfies Searchable interface (implicitly).

type Library struct {
	Name    string
	books   []*Book   // Composition: owns these
	members []*Member // Aggregation: has these, doesn't own
}

func NewLibrary(name string) *Library {
	return &Library{Name: name}
}

func (l *Library) AddBook(b *Book) {
	l.books = append(l.books, b)
}

func (l *Library) RegisterMember(m *Member) {
	l.members = append(l.members, m)
}

// Implements Searchable implicitly
func (l *Library) Search(title string) *Book {
	for _, b := range l.books {
		if strings.EqualFold(b.Title, title) {
			return b
		}
	}
	return nil
}

func (l *Library) SearchByAuthor(authorName string) []*Book {
	var results []*Book
	for _, b := range l.books {
		if strings.EqualFold(b.Author.Name, authorName) {
			results = append(results, b)
		}
	}
	return results
}

func (l *Library) DisplayInfo() {
	fmt.Printf("Library: %s\n", l.Name)
	fmt.Printf("Books (%d):\n", len(l.books))
	for _, b := range l.books {
		fmt.Printf("  - %s by %s\n", b.Title, b.Author.Name)
	}
	fmt.Printf("Members (%d):\n", len(l.members))
	for _, m := range l.members {
		fmt.Printf("  - %s (%s)\n", m.Name, m.MemberID)
	}
}

func (l *Library) Books() []*Book {
	return l.books
}

func (l *Library) Members() []*Member {
	return l.members
}
