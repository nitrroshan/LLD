package main

// Go does NOT support method overloading.
// Use different function names instead.

func AddInt(a, b int) int          { return a + b }
func AddFloat(a, b float64) float64 { return a + b }
func AddThree(a, b, c int) int     { return a + b + c }
