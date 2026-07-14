package main

// DefaultBeverage provides the hook's default via embedding. Types that embed
// it inherit WantsCondiments() == true unless they override it — Go's
// composition-based way to give a "hook a default implementation".
type DefaultBeverage struct{}

func (DefaultBeverage) WantsCondiments() bool { return true }
