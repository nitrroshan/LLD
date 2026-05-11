package main

import "fmt"

// Abstraction — high-level remote control operations.
type Remote struct {
	device Device // ← THE BRIDGE
}

func NewRemote(device Device) *Remote {
	return &Remote{device: device}
}

func (r *Remote) TogglePower() {
	fmt.Printf("[%s Remote] Toggle power\n", r.device.GetName())
	if r.device.IsEnabled() {
		r.device.Disable()
	} else {
		r.device.Enable()
	}
}

func (r *Remote) VolumeUp() {
	fmt.Printf("[%s Remote] Volume up\n", r.device.GetName())
	r.device.SetVolume(r.device.GetVolume() + 10)
}

func (r *Remote) VolumeDown() {
	fmt.Printf("[%s Remote] Volume down\n", r.device.GetName())
	r.device.SetVolume(r.device.GetVolume() - 10)
}

func (r *Remote) ChannelUp() {
	fmt.Printf("[%s Remote] Channel up\n", r.device.GetName())
	r.device.SetChannel(r.device.GetChannel() + 1)
}
