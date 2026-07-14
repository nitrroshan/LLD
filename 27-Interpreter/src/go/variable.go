package main

// Variable is a Terminal Expression — it looks up its value in the context.
type Variable struct {
	name string
}

func NewVariable(name string) *Variable {
	return &Variable{name: name}
}

func (v *Variable) Interpret(context *Context) bool {
	return context.Get(v.name)
}
