package main

// Go interfaces are satisfied IMPLICITLY — no "implements" keyword.

type Animal interface {
	GetName() string
	Eat()
	MakeSound()
}
