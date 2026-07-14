package main

import "fmt"

// ProxyImage is the Virtual Proxy — same Image interface, but defers the
// expensive load until Display() is first called (lazy loading).
type ProxyImage struct {
	filename  string
	realImage *RealImage // nil until first use
}

func NewProxyImage(filename string) *ProxyImage {
	fmt.Printf("  [ProxyImage] Created for %s (nothing loaded yet)\n", filename)
	return &ProxyImage{filename: filename}
}

func (p *ProxyImage) Display() {
	if p.realImage == nil {
		p.realImage = NewRealImage(p.filename) // create on first display only
	}
	p.realImage.Display()
}
