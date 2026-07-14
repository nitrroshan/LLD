package main

import "fmt"

// ChatUser is a Concrete Colleague. It holds only the mediator, never a
// reference to another user.
type ChatUser struct {
	name     string
	mediator ChatMediator
}

func NewChatUser(mediator ChatMediator, name string) *ChatUser {
	return &ChatUser{name: name, mediator: mediator}
}

func (u *ChatUser) Name() string { return u.name }

// Send routes the message through the mediator, not to peers directly.
func (u *ChatUser) Send(message string) {
	fmt.Printf("%s sends: %s\n", u.name, message)
	u.mediator.SendMessage(message, u)
}

func (u *ChatUser) Receive(message, from string) {
	fmt.Printf("    %s received from %s: %s\n", u.name, from, message)
}
