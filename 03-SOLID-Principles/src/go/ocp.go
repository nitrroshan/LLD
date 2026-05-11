package main

// OCP — Open/Closed Principle
// New discount types = new structs satisfying the interface

type DiscountStrategy interface {
	Calculate(amount float64) float64
}

type RegularDiscount struct{}
func (RegularDiscount) Calculate(amount float64) float64 { return amount * 0.05 }

type PremiumDiscount struct{}
func (PremiumDiscount) Calculate(amount float64) float64 { return amount * 0.10 }

type VIPDiscount struct{}
func (VIPDiscount) Calculate(amount float64) float64 { return amount * 0.20 }

type EmployeeDiscount struct{}
func (EmployeeDiscount) Calculate(amount float64) float64 { return amount * 0.30 }

func CalculateDiscount(s DiscountStrategy, amount float64) float64 {
	return s.Calculate(amount)
}
