package main

// Implementation interface — low-level device operations.
type Device interface {
	IsEnabled() bool
	Enable()
	Disable()
	GetVolume() int
	SetVolume(volume int)
	GetChannel() int
	SetChannel(channel int)
	GetName() string
}
