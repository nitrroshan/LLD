package main

import "fmt"

type NoQuarterState struct {
	machine *GumballMachine
}

func (s *NoQuarterState) InsertQuarter() {
	fmt.Println("  You inserted a quarter")
	s.machine.setState(s.machine.hasQuarter)
}
func (s *NoQuarterState) EjectQuarter() {
	fmt.Println("  You haven't inserted a quarter")
}
func (s *NoQuarterState) TurnCrank() {
	fmt.Println("  You turned, but there's no quarter")
}
func (s *NoQuarterState) Dispense() {
	fmt.Println("  You need to pay first")
}
func (s *NoQuarterState) Name() string { return "NoQuarter" }
