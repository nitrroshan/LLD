package main

import "fmt"

// SRP — Single Responsibility Principle

type Invoice struct {
	Product      string
	Quantity     int
	PricePerUnit float64
}

func (i *Invoice) Total() float64 { return float64(i.Quantity) * i.PricePerUnit }

type InvoicePrinter struct{}

func (InvoicePrinter) Print(inv *Invoice) {
	fmt.Printf("Invoice: %s x%d = $%.2f\n", inv.Product, inv.Quantity, inv.Total())
}

type InvoiceRepository struct{}

func (InvoiceRepository) Save(inv *Invoice) {
	fmt.Printf("[DB] Saving invoice for %s\n", inv.Product)
}
