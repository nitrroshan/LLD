package main

import "fmt"

// Product interface — all menus must render and support selection
type Menu interface {
	Render()
	Select(item string)
}

// Windows family
type WindowsMenu struct{}

func (WindowsMenu) Render() {
	fmt.Println("[Windows Menu] Rendering dropdown menu with separator lines.")
}

func (WindowsMenu) Select(item string) {
	fmt.Println("[Windows Menu] Selected:", item, "— Windows style.")
}

// Mac family
type MacMenu struct{}

func (MacMenu) Render() {
	fmt.Println("[Mac Menu] Rendering translucent menu with vibrancy effect.")
}

func (MacMenu) Select(item string) {
	fmt.Println("[Mac Menu] Selected:", item, "— macOS style.")
}
