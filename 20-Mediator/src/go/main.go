package main

import "fmt"

func main() {
	fmt.Println("=== Mediator Pattern Demo (Go) ===")
	fmt.Println()

	// The mediator
	chatRoom := &ChatRoom{}

	// Colleagues — each knows only the chat room, never each other
	alice := NewChatUser(chatRoom, "Alice")
	bob := NewChatUser(chatRoom, "Bob")
	carol := NewChatUser(chatRoom, "Carol")

	chatRoom.AddUser(alice)
	chatRoom.AddUser(bob)
	chatRoom.AddUser(carol)

	// Alice sends — the room delivers to Bob and Carol (not back to Alice)
	alice.Send("Hi everyone!")
	fmt.Println()

	// Bob replies — same mechanism, zero direct user-to-user references
	bob.Send("Hey Alice!")

	fmt.Println("\nNo user holds a reference to another user —")
	fmt.Println("all coordination lives in the ChatRoom mediator.")
}
