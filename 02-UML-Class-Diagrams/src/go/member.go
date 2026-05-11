package main

import "fmt"

// Aggregation: Library has Members (they exist independently).
// Dependency: Member uses Book in Borrow() but doesn't store it.

type Member struct {
	MemberID string
	Name     string
}

func NewMember(memberID, name string) *Member {
	return &Member{MemberID: memberID, Name: name}
}

// Dependency: uses Book as parameter only
func (m *Member) Borrow(b *Book) {
	fmt.Printf("%s borrowed: %s\n", m.Name, b.Title)
}
