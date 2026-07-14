package main

// Image is the Subject — the common interface shared by the real object
// and the proxy. Clients depend only on this.
type Image interface {
	Display()
}
