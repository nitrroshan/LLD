package main

import "fmt"

// Inheritance: Go doesn't have inheritance — use embedding (composition).
// DigitalBook embeds Book and adds extra fields.

type DigitalBook struct {
	*Book              // Embedding = promoted fields/methods (like inheritance)
	Format     string
	FileSizeMb float64
}

func NewDigitalBook(title, isbn string, author *Author, format string, fileSizeMb float64) *DigitalBook {
	return &DigitalBook{
		Book:       NewBook(title, isbn, author),
		Format:     format,
		FileSizeMb: fileSizeMb,
	}
}

// Override DisplayInfo — Go dispatches to this if called on *DigitalBook
func (d *DigitalBook) DisplayInfo() {
	fmt.Printf("[DigitalBook] %s by %s | Format: %s | Size: %.1fMB\n",
		d.Title, d.Author.Name, d.Format, d.FileSizeMb)
}
