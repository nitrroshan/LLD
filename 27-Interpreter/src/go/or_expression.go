package main

// OrExpression is a Non-terminal Expression — logical OR of two sub-expressions.
type OrExpression struct {
	left  Expression
	right Expression
}

func NewOrExpression(left, right Expression) *OrExpression {
	return &OrExpression{left: left, right: right}
}

func (o *OrExpression) Interpret(context *Context) bool {
	return o.left.Interpret(context) || o.right.Interpret(context)
}
