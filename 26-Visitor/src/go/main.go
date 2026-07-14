package main

import "fmt"

func main() {
	fmt.Println("=== Visitor Pattern Demo (Go) ===")
	fmt.Println()

	// Build the expression tree: (3 + 4) * 5
	expression := NewMultiplication(
		NewAddition(NewNumberExpr(3), NewNumberExpr(4)),
		NewNumberExpr(5),
	)

	// Operation 1: print — a visitor
	printer := &PrintVisitor{}
	expression.Accept(printer)
	fmt.Printf("Expression: %s\n", printer.Result())

	// Operation 2: evaluate — another visitor, same elements
	evaluator := &EvaluateVisitor{}
	expression.Accept(evaluator)
	fmt.Printf("Value:      %g\n", evaluator.Result())

	fmt.Println("\nTwo operations, zero changes to the element classes —")
	fmt.Println("each visitor added a new operation on its own.")
}
