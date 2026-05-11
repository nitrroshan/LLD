package main

import "fmt"

// ISP — Interface Segregation Principle

type Printable interface {
	Print(doc string)
}

type Scannable interface {
	Scan(doc string)
}

type Faxable interface {
	Fax(doc string)
}

type AllInOnePrinter struct{}
func (AllInOnePrinter) Print(doc string) { fmt.Println("Printing:", doc) }
func (AllInOnePrinter) Scan(doc string)  { fmt.Println("Scanning:", doc) }
func (AllInOnePrinter) Fax(doc string)   { fmt.Println("Faxing:", doc) }

type SimplePrinterISP struct{}
func (SimplePrinterISP) Print(doc string) { fmt.Println("Printing:", doc) }
// No Scan, no Fax — only satisfies Printable
