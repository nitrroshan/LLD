package main

// User is the Colleague interface. Each colleague knows only the mediator.
type User interface {
	Send(message string)
	Receive(message, from string)
	Name() string
}
