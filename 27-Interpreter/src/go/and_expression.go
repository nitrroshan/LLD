package main

// AndExpression is a Non-terminal Expression — logical AND of two sub-expressions.
type AndExpression struct {
	left  Expression
	right Expression
}

func NewAndExpression(left, right Expression) *AndExpression {
	return &AndExpression{left: left, right: right}
}

func (a *AndExpression) Interpret(context *Context) bool {
	return a.left.Interpret(context) && a.right.Interpret(context)
}
