package main

import "fmt"

// Product interface — all buttons must render and handle clicks
type Button interface {
	Render()
	OnClick()
}

// Windows family
type WindowsButton struct{}

func (WindowsButton) Render() {
	fmt.Println("[Windows Button] Rendering flat-style button with sharp corners.")
}

func (WindowsButton) OnClick() {
	fmt.Println("[Windows Button] Click — executing Windows command.")
}

// Mac family
type MacButton struct{}

func (MacButton) Render() {
	fmt.Println("[Mac Button] Rendering rounded Aqua-style button.")
}

func (MacButton) OnClick() {
	fmt.Println("[Mac Button] Click — executing macOS command.")
}
