package main

import "fmt"

// HomeTheaterFacade — simple interface over the home theater subsystem.
// It holds the subsystem components and sequences their calls.
type HomeTheaterFacade struct {
	projector Projector
	screen    Screen
	amplifier Amplifier
	lights    TheaterLights
	dvdPlayer DvdPlayer
}

func NewHomeTheaterFacade(projector Projector, screen Screen, amplifier Amplifier,
	lights TheaterLights, dvdPlayer DvdPlayer) *HomeTheaterFacade {
	return &HomeTheaterFacade{
		projector: projector,
		screen:    screen,
		amplifier: amplifier,
		lights:    lights,
		dvdPlayer: dvdPlayer,
	}
}

func (h *HomeTheaterFacade) WatchMovie(movie string) {
	fmt.Println("Get ready to watch a movie...")
	h.lights.Dim(10)
	h.screen.Down()
	h.projector.On()
	h.projector.WideScreenMode()
	h.amplifier.On()
	h.amplifier.SetVolume(8)
	h.dvdPlayer.On()
	h.dvdPlayer.Play(movie)
}

func (h *HomeTheaterFacade) EndMovie() {
	fmt.Println("Shutting movie theater down...")
	h.dvdPlayer.Stop()
	h.dvdPlayer.Off()
	h.amplifier.Off()
	h.projector.Off()
	h.screen.Up()
	h.lights.On()
}
