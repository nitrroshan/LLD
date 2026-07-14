package main

import "fmt"

// Song is the element stored in the collection.
type Song struct {
	title  string
	artist string
}

func NewSong(title, artist string) Song {
	return Song{title: title, artist: artist}
}

func (s Song) String() string {
	return fmt.Sprintf("%q by %s", s.title, s.artist)
}
