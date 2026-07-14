package main

// State declares the actions whose behavior depends on the machine's state.
type State interface {
	InsertQuarter()
	EjectQuarter()
	TurnCrank()
	Dispense()
	Name() string
}
