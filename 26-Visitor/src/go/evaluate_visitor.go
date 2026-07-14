package main

// EvaluateVisitor computes the numeric value of the expression. Binary nodes
// recursively visit their children and combine the results.
type EvaluateVisitor struct {
	result float64
}

func (e *EvaluateVisitor) Result() float64 { return e.result }

func (e *EvaluateVisitor) VisitNumber(number *NumberExpr) {
	e.result = number.Value()
}

func (e *EvaluateVisitor) VisitAddition(addition *Addition) {
	addition.Left().Accept(e)
	left := e.result
	addition.Right().Accept(e)
	right := e.result
	e.result = left + right
}

func (e *EvaluateVisitor) VisitMultiplication(multiplication *Multiplication) {
	multiplication.Left().Accept(e)
	left := e.result
	multiplication.Right().Accept(e)
	right := e.result
	e.result = left * right
}
