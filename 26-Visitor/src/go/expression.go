package main

// Expression is the Element — it declares Accept(visitor).
type Expression interface {
	Accept(visitor Visitor)
}
