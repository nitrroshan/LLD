package main

import "fmt"

type Radio struct {
	enabled bool
	volume  int
	channel int
}

func NewRadio() *Radio {
	return &Radio{enabled: false, volume: 20, channel: 88}
}

func (r *Radio) IsEnabled() bool { return r.enabled }

func (r *Radio) Enable() {
	r.enabled = true
	fmt.Println("  Radio is ON")
}

func (r *Radio) Disable() {
	r.enabled = false
	fmt.Println("  Radio is OFF")
}

func (r *Radio) GetVolume() int { return r.volume }

func (r *Radio) SetVolume(volume int) {
	if volume < 0 {
		volume = 0
	} else if volume > 100 {
		volume = 100
	}
	r.volume = volume
	fmt.Printf("  Radio volume: %d\n", r.volume)
}

func (r *Radio) GetChannel() int { return r.channel }

func (r *Radio) SetChannel(channel int) {
	r.channel = channel
	fmt.Printf("  Radio station: %d FM\n", r.channel)
}

func (r *Radio) GetName() string { return "Radio" }
