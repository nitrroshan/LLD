// Chapter 05 — Factory Method Pattern in Go
// Run: go run .

package main

import "fmt"

func main() {
	fmt.Println("=== Road Logistics ===")
	PlanDelivery(RoadLogistics{})

	fmt.Println("\n=== Sea Logistics ===")
	PlanDelivery(SeaLogistics{})

	fmt.Println("\n=== Air Logistics ===")
	PlanDelivery(AirLogistics{})

	fmt.Println("\n=== All Logistics (interface polymorphism) ===")
	factories := []LogisticsFactory{RoadLogistics{}, SeaLogistics{}, AirLogistics{}}
	for _, f := range factories {
		PlanDelivery(f)
	}
}
