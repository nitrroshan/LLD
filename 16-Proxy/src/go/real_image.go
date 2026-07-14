package main

import "fmt"

// RealImage is the RealSubject — the expensive object. The costly load
// is simulated in the constructor.
type RealImage struct {
	filename string
}

func NewRealImage(filename string) *RealImage {
	img := &RealImage{filename: filename}
	img.loadFromDisk()
	return img
}

func (r *RealImage) loadFromDisk() {
	fmt.Printf("  [RealImage] Loading %s from disk (expensive)...\n", r.filename)
}

func (r *RealImage) Display() {
	fmt.Printf("  [RealImage] Displaying %s\n", r.filename)
}
