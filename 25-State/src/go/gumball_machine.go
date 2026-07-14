package main

import (
	"fmt"
)

// GumballMachine is the Context — it owns the states, delegates actions to the
// current one, and holds the shared gumball count.
type GumballMachine struct {
	noQuarter  State
	hasQuarter State
	sold       State
	soldOut    State

	current State
	count   int
}

func NewGumballMachine(count int) *GumballMachine {
	m := &GumballMachine{count: count}
	m.noQuarter = &NoQuarterState{machine: m}
	m.hasQuarter = &HasQuarterState{machine: m}
	m.sold = &SoldState{machine: m}
	m.soldOut = &SoldOutState{machine: m}
	if count > 0 {
		m.current = m.noQuarter
	} else {
		m.current = m.soldOut
	}
	return m
}

func (m *GumballMachine) InsertQuarter() { m.current.InsertQuarter() }
func (m *GumballMachine) EjectQuarter()  { m.current.EjectQuarter() }
func (m *GumballMachine) TurnCrank() {
	m.current.TurnCrank()
	m.current.Dispense()
}

func (m *GumballMachine) setState(state State) { m.current = state }

func (m *GumballMachine) releaseBall() {
	if m.count > 0 {
		fmt.Println("  A gumball rolls out...")
		m.count--
	}
}

func (m *GumballMachine) Status() string {
	return fmt.Sprintf("[state=%s, gumballs=%d]", m.current.Name(), m.count)
}
