package main

// Abstract Factory — declares creation methods for each product in the family.
// NOTE: Go uses interfaces instead of abstract classes.
// Business logic is in a free function BuildUI() since Go interfaces can't have default methods.

type UIFactory interface {
	CreateButton() Button
	CreateCheckbox() Checkbox
	CreateMenu() Menu
}

// Concrete Factory — Windows family
type WindowsFactory struct{}

func (WindowsFactory) CreateButton() Button     { return WindowsButton{} }
func (WindowsFactory) CreateCheckbox() Checkbox { return WindowsCheckbox{} }
func (WindowsFactory) CreateMenu() Menu         { return WindowsMenu{} }

// Concrete Factory — Mac family
type MacFactory struct{}

func (MacFactory) CreateButton() Button     { return MacButton{} }
func (MacFactory) CreateCheckbox() Checkbox { return MacCheckbox{} }
func (MacFactory) CreateMenu() Menu         { return MacMenu{} }
