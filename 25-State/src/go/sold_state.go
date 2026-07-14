package main

import "fmt"

type SoldState struct {
	machine *GumballMachine
}

func (s *SoldState) InsertQuarter() {
	fmt.Println("  Please wait, we're already giving you a gumball")
}
func (s *SoldState) EjectQuarter() {
	fmt.Println("  Sorry, you already turned the crank")
}
func (s *SoldState) TurnCrank() {
	fmt.Println("  Turning twice doesn't get you another gumball")
}
func (s *SoldState) Dispense() {
	s.machine.releaseBall()
	if s.machine.count > 0 {
		s.machine.setState(s.machine.noQuarter)
	} else {
		fmt.Println("  Oops, out of gumballs!")
		s.machine.setState(s.machine.soldOut)
	}
}
func (s *SoldState) Name() string { return "Sold" }
