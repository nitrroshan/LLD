package main

import "fmt"

// PrintVisitor renders the expression as infix text. Adding this operation
// required NO change to any element class.
type PrintVisitor struct {
	result string
}

func (p *PrintVisitor) Result() string { return p.result }

func (p *PrintVisitor) VisitNumber(number *NumberExpr) {
	p.result = fmt.Sprintf("%g", number.Value())
}

func (p *PrintVisitor) VisitAddition(addition *Addition) {
	addition.Left().Accept(p)
	left := p.result
	addition.Right().Accept(p)
	right := p.result
	p.result = "(" + left + " + " + right + ")"
}

func (p *PrintVisitor) VisitMultiplication(multiplication *Multiplication) {
	multiplication.Left().Accept(p)
	left := p.result
	multiplication.Right().Accept(p)
	right := p.result
	p.result = "(" + left + " * " + right + ")"
}
