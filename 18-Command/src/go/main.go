package main

import "fmt"

func main() {
	fmt.Println("=== Command Pattern Demo (Go) ===")
	fmt.Println()

	// Receivers
	livingRoom := NewLight("Living Room")
	kitchen := NewLight("Kitchen")

	// Concrete commands binding actions to receivers
	livingRoomOn := NewLightOnCommand(livingRoom)
	livingRoomOff := NewLightOffCommand(livingRoom)
	kitchenOn := NewLightOnCommand(kitchen)

	remote := &RemoteControl{}

	fmt.Println("Turn living room light on:")
	remote.SetCommand(livingRoomOn)
	remote.PressButton()

	fmt.Println("\nTurn it off:")
	remote.SetCommand(livingRoomOff)
	remote.PressButton()

	fmt.Println("\nUndo (should turn back on):")
	remote.PressUndo()

	fmt.Println("\nUndo again (should turn off):")
	remote.PressUndo()

	// Macro command — "party mode"
	fmt.Println("\n--- Macro Command: Party Mode ---")
	partyMode := NewMacroCommand(livingRoomOn, kitchenOn)
	remote.SetCommand(partyMode)
	remote.PressButton()

	fmt.Println("\nUndo party mode (reverses both, in reverse order):")
	remote.PressUndo()
}
