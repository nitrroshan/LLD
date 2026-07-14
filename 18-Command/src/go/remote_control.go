package main

import "fmt"

// RemoteControl is the Invoker — holds a command, triggers it, and records
// history for undo. It knows nothing about receivers.
type RemoteControl struct {
	slot    Command
	history []Command
}

func (r *RemoteControl) SetCommand(command Command) {
	r.slot = command
}

func (r *RemoteControl) PressButton() {
	if r.slot != nil {
		r.slot.Execute()
		r.history = append(r.history, r.slot)
	}
}

func (r *RemoteControl) PressUndo() {
	if len(r.history) == 0 {
		fmt.Println("  [undo] nothing to undo")
		return
	}
	fmt.Println("  [undo]")
	last := r.history[len(r.history)-1]
	r.history = r.history[:len(r.history)-1]
	last.Undo()
}
