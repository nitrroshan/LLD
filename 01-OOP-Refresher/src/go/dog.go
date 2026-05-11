package main

import "fmt"

type Dog struct {
	Name  string
	Breed string
}

func (d *Dog) GetName() string { return d.Name }

func (d *Dog) Eat() {
	fmt.Printf("%s is eating.\n", d.Name)
}

func (d *Dog) MakeSound() {
	fmt.Printf("%s says Woof! [%s]\n", d.Name, d.Breed)
}

func (d *Dog) Fetch() {
	fmt.Printf("%s fetches the ball!\n", d.Name)
}
