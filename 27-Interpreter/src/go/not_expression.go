package main

// NotExpression is a Non-terminal Expression — logical NOT of one sub-expression.
type NotExpression struct {
	expression Expression
}

func NewNotExpression(expression Expression) *NotExpression {
	return &NotExpression{expression: expression}
}

func (n *NotExpression) Interpret(context *Context) bool {
	return !n.expression.Interpret(context)
}
