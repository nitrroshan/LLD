package main

// Expression is the AbstractExpression — every grammar rule implements it.
type Expression interface {
	Interpret(context *Context) bool
}
