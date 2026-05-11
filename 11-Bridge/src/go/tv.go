package main

import "fmt"

type Tv struct {
	enabled bool
	volume  int
	channel int
}

func NewTv() *Tv {
	return &Tv{enabled: false, volume: 30, channel: 1}
}

func (t *Tv) IsEnabled() bool { return t.enabled }

func (t *Tv) Enable() {
	t.enabled = true
	fmt.Println("  TV is ON")
}

func (t *Tv) Disable() {
	t.enabled = false
	fmt.Println("  TV is OFF")
}

func (t *Tv) GetVolume() int { return t.volume }

func (t *Tv) SetVolume(volume int) {
	if volume < 0 {
		volume = 0
	} else if volume > 100 {
		volume = 100
	}
	t.volume = volume
	fmt.Printf("  TV volume: %d\n", t.volume)
}

func (t *Tv) GetChannel() int { return t.channel }

func (t *Tv) SetChannel(channel int) {
	t.channel = channel
	fmt.Printf("  TV channel: %d\n", t.channel)
}

func (t *Tv) GetName() string { return "TV" }
