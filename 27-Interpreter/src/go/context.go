package main

// Context holds the boolean value bound to each variable name.
type Context struct {
	values map[string]bool
}

func NewContext() *Context {
	return &Context{values: make(map[string]bool)}
}

func (c *Context) Set(name string, value bool) {
	c.values[name] = value
}

func (c *Context) Get(name string) bool {
	return c.values[name]
}
