package main

import "fmt"

func evaluate(rule Expression, a, b, c bool) {
	context := NewContext()
	context.Set("A", a)
	context.Set("B", b)
	context.Set("C", c)
	fmt.Printf("  A=%t, B=%t, C=%t -> %t\n", a, b, c, rule.Interpret(context))
}

func main() {
	fmt.Println("=== Interpreter Pattern Demo (Go) ===")
	fmt.Println()

	// Build the rule tree for: (A OR B) AND (NOT C)
	rule := NewAndExpression(
		NewOrExpression(NewVariable("A"), NewVariable("B")),
		NewNotExpression(NewVariable("C")),
	)

	fmt.Println("Rule: (A OR B) AND (NOT C)")
	fmt.Println()

	evaluate(rule, true, false, false)
	evaluate(rule, false, false, false)
	evaluate(rule, true, true, true)
}
