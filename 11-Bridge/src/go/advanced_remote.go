package main

import "fmt"

// Refined Abstraction — advanced remote with extra features.
type AdvancedRemote struct {
	Remote // embeds Remote — inherits basic operations
}

func NewAdvancedRemote(device Device) *AdvancedRemote {
	return &AdvancedRemote{Remote: Remote{device: device}}
}

func (a *AdvancedRemote) Mute() {
	fmt.Printf("[%s Advanced Remote] Mute\n", a.device.GetName())
	a.device.SetVolume(0)
}

func (a *AdvancedRemote) SetChannelDirect(channel int) {
	fmt.Printf("[%s Advanced Remote] Go to channel %d\n", a.device.GetName(), channel)
	a.device.SetChannel(channel)
}

func (a *AdvancedRemote) PrintStatus() {
	power := "OFF"
	if a.device.IsEnabled() {
		power = "ON"
	}
	fmt.Printf("[%s Status] power=%s volume=%d channel=%d\n",
		a.device.GetName(), power, a.device.GetVolume(), a.device.GetChannel())
}
