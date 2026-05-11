package main

import "fmt"

type House struct {
	rooms     int
	floors    int
	hasGarage bool
	hasPool   bool
	hasGarden bool
	roofType  string
}

func (h House) String() string {
	s := fmt.Sprintf("House [%d rooms, %d floors, roof=%s", h.rooms, h.floors, h.roofType)
	if h.hasGarage {
		s += ", garage"
	}
	if h.hasPool {
		s += ", pool"
	}
	if h.hasGarden {
		s += ", garden"
	}
	s += "]"
	return s
}
