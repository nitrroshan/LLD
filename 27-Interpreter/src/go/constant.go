package main

// Constant is a Terminal Expression — a literal true/false value.
type Constant struct {
	value bool
}

func NewConstant(value bool) *Constant {
	return &Constant{value: value}
}

func (c *Constant) Interpret(context *Context) bool {
	return c.value
}
