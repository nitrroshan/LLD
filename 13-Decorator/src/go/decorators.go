package main

import "fmt"

type MilkDecorator struct {
	wrapped Coffee
}

func WithMilk(c Coffee) Coffee {
	return &MilkDecorator{wrapped: c}
}

func (m *MilkDecorator) GetDescription() string {
	return fmt.Sprintf("%s, Milk", m.wrapped.GetDescription())
}

func (m *MilkDecorator) GetCost() float64 {
	return m.wrapped.GetCost() + 0.50
}

type WhipDecorator struct {
	wrapped Coffee
}

func WithWhip(c Coffee) Coffee {
	return &WhipDecorator{wrapped: c}
}

func (w *WhipDecorator) GetDescription() string {
	return fmt.Sprintf("%s, Whip", w.wrapped.GetDescription())
}

func (w *WhipDecorator) GetCost() float64 {
	return w.wrapped.GetCost() + 0.70
}

type CaramelDecorator struct {
	wrapped Coffee
}

func WithCaramel(c Coffee) Coffee {
	return &CaramelDecorator{wrapped: c}
}

func (c *CaramelDecorator) GetDescription() string {
	return fmt.Sprintf("%s, Caramel", c.wrapped.GetDescription())
}

func (c *CaramelDecorator) GetCost() float64 {
	return c.wrapped.GetCost() + 0.60
}
