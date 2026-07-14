package main

// ChatMediator declares how colleagues communicate. Colleagues talk to this,
// never to each other directly.
type ChatMediator interface {
	SendMessage(message string, sender User)
	AddUser(user User)
}
