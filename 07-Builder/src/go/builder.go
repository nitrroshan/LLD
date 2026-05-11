package main

import "fmt"

type HouseBuilder struct {
	rooms     int
	floors    int
	hasGarage bool
	hasPool   bool
	hasGarden bool
	roofType  string
}

func NewHouseBuilder() *HouseBuilder {
	return &HouseBuilder{
		rooms:    1,
		floors:   1,
		roofType: "shingle",
	}
}

func (b *HouseBuilder) Rooms(count int) *HouseBuilder {
	b.rooms = count
	return b
}

func (b *HouseBuilder) Floors(count int) *HouseBuilder {
	b.floors = count
	return b
}

func (b *HouseBuilder) Garage() *HouseBuilder {
	b.hasGarage = true
	return b
}

func (b *HouseBuilder) Pool() *HouseBuilder {
	b.hasPool = true
	return b
}

func (b *HouseBuilder) Garden() *HouseBuilder {
	b.hasGarden = true
	return b
}

func (b *HouseBuilder) RoofType(roofType string) *HouseBuilder {
	b.roofType = roofType
	return b
}

func (b *HouseBuilder) Build() House {
	if b.rooms < 1 {
		panic(fmt.Sprintf("House must have at least 1 room, got %d", b.rooms))
	}
	if b.floors < 1 {
		panic(fmt.Sprintf("House must have at least 1 floor, got %d", b.floors))
	}
	return House{
		rooms:     b.rooms,
		floors:    b.floors,
		hasGarage: b.hasGarage,
		hasPool:   b.hasPool,
		hasGarden: b.hasGarden,
		roofType:  b.roofType,
	}
}
