package main

// PurchaseRequest is the request that travels along the chain of handlers.
type PurchaseRequest struct {
	Amount  float64
	Purpose string
}
