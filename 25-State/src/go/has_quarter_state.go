package main

import "fmt"

type HasQuarterState struct {
	machine *GumballMachine
}

func (s *HasQuarterState) InsertQuarter() {
	fmt.Println("  You can't insert another quarter")
}
func (s *HasQuarterState) EjectQuarter() {
	fmt.Println("  Quarter returned")
	s.machine.setState(s.machine.noQuarter)
}
func (s *HasQuarterState) TurnCrank() {
	fmt.Println("  You turned the crank...")
	s.machine.setState(s.machine.sold)
}
func (s *HasQuarterState) Dispense() {
	fmt.Println("  No gumball dispensed")
}
func (s *HasQuarterState) Name() string { return "HasQuarter" }
