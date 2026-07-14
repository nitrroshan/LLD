package main

// Visitor declares one visit method per concrete element type. Go has no
// method overloading, so each is named for its type — exactly the Visitor shape.
type Visitor interface {
	VisitNumber(number *NumberExpr)
	VisitAddition(addition *Addition)
	VisitMultiplication(multiplication *Multiplication)
}
