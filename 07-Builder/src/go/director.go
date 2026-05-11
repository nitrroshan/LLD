package main

type HouseDirector struct{}

func (d HouseDirector) BuildLuxuryHouse() House {
	return NewHouseBuilder().
		Rooms(6).Floors(3).
		Garage().Pool().Garden().
		RoofType("slate").
		Build()
}

func (d HouseDirector) BuildSimpleHouse() House {
	return NewHouseBuilder().
		Rooms(2).Floors(1).
		RoofType("shingle").
		Build()
}

func (d HouseDirector) BuildFamilyHouse() House {
	return NewHouseBuilder().
		Rooms(4).Floors(2).
		Garage().Garden().
		RoofType("tile").
		Build()
}
