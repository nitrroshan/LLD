package main

import "fmt"

type Cat struct {
	Name string
}

func (c *Cat) GetName() string { return c.Name }

func (c *Cat) Eat() {
	fmt.Printf("%s is eating.\n", c.Name)
}

func (c *Cat) MakeSound() {
	fmt.Printf("%s says Meow!\n", c.Name)
}

func (c *Cat) Purr() {
	fmt.Printf("%s is purring...\n", c.Name)
}
