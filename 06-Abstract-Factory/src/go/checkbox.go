package main

import "fmt"

// Product interface — all checkboxes must render and toggle
type Checkbox interface {
	Render()
	Toggle()
}

// Windows family
type WindowsCheckbox struct{}

func (WindowsCheckbox) Render() {
	fmt.Println("[Windows Checkbox] Rendering square checkbox with checkmark.")
}

func (WindowsCheckbox) Toggle() {
	fmt.Println("[Windows Checkbox] Toggled — Windows style.")
}

// Mac family
type MacCheckbox struct{}

func (MacCheckbox) Render() {
	fmt.Println("[Mac Checkbox] Rendering rounded checkbox with smooth animation.")
}

func (MacCheckbox) Toggle() {
	fmt.Println("[Mac Checkbox] Toggled — macOS style.")
}
