package main

// ChatRoom is the Concrete Mediator — it holds the colleagues and owns the
// coordination logic: broadcast to everyone except the sender.
type ChatRoom struct {
	users []User
}

func (c *ChatRoom) AddUser(user User) {
	c.users = append(c.users, user)
}

func (c *ChatRoom) SendMessage(message string, sender User) {
	for _, user := range c.users {
		if user != sender {
			user.Receive(message, sender.Name())
		}
	}
}
