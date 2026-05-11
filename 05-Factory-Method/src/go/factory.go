package main

import "fmt"

// Creator interface — Go uses interface, not abstract class
// NOTE: Go can't have default methods on interfaces.
// We use a free function PlanDelivery() that takes the factory.

type LogisticsFactory interface {
	CreateTransport() Transport
}

// Free function with business logic (since Go interfaces can't have default methods)
func PlanDelivery(factory LogisticsFactory) {
	transport := factory.CreateTransport()
	fmt.Println("Planning delivery with:", transport.Name())
	transport.Deliver()
}

// Concrete Creators
type RoadLogistics struct{}
func (RoadLogistics) CreateTransport() Transport { return Truck{} }

type SeaLogistics struct{}
func (SeaLogistics) CreateTransport() Transport { return Ship{} }

type AirLogistics struct{}
func (AirLogistics) CreateTransport() Transport { return Airplane{} }
