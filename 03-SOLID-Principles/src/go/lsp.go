package main

import "fmt"

// LSP — Liskov Substitution Principle
// Separate interfaces for separate capabilities

type BirdLike interface {
	Name() string
}

type Flyable interface {
	Fly()
}

type Sparrow struct{}
func (Sparrow) Name() string { return "Sparrow" }
func (Sparrow) Fly()         { fmt.Println("Sparrow is flying!") }

type PenguinGood struct{}
func (PenguinGood) Name() string { return "Penguin" }
func (PenguinGood) Swim()        { fmt.Println("Penguin is swimming!") }
// No Fly() — Penguin doesn't satisfy Flyable

func MakeFly(f Flyable) {
	f.Fly()
}
