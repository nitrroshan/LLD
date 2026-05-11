package main

// Association target: Book knows Author, Author exists independently.

type Author struct {
	Name  string
	Email string
}

func NewAuthor(name, email string) *Author {
	return &Author{Name: name, Email: email}
}
