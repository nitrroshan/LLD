package main

import "fmt"

// Product interface
type Transport interface {
	Deliver()
	Name() string
}

type Truck struct{}
func (Truck) Deliver() { fmt.Println("Delivering by land in a truck.") }
func (Truck) Name() string { return "Truck" }

type Ship struct{}
func (Ship) Deliver() { fmt.Println("Delivering by sea in a container ship.") }
func (Ship) Name() string { return "Ship" }

type Airplane struct{}
func (Airplane) Deliver() { fmt.Println("Delivering by air in a cargo airplane.") }
func (Airplane) Name() string { return "Airplane" }
