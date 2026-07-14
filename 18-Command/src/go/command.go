package main

// Command bundles an action with its receiver. Execute performs it;
// Undo reverses it.
type Command interface {
	Execute()
	Undo()
}
