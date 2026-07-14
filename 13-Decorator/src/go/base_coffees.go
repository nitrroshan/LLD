package main

type Espresso struct{}

func (e Espresso) GetDescription() string { return "Espresso" }
func (e Espresso) GetCost() float64       { return 2.00 }

type Latte struct{}

func (l Latte) GetDescription() string { return "Latte" }
func (l Latte) GetCost() float64       { return 3.00 }
