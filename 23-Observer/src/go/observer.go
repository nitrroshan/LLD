package main

// Observer is the update interface all subscribers implement (push model).
type Observer interface {
	Update(temperature float64)
}
