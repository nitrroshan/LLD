package main

import (
	"fmt"
	"time"
)

// Third-party Stripe API — different interface, amounts in cents.
type StripeApi struct{}

type StripeResult struct {
	Success bool
	ID      string
}

func (s *StripeApi) CreateCharge(cents int, currency, token string) StripeResult {
	fmt.Printf("  [Stripe] Charging %d cents (%s) token=%s\n", cents, currency, token)
	return StripeResult{Success: true, ID: fmt.Sprintf("ch_%d", time.Now().UnixNano())}
}

func (s *StripeApi) CreateRefund(chargeId string) StripeResult {
	fmt.Printf("  [Stripe] Refunding charge %s\n", chargeId)
	return StripeResult{Success: true, ID: fmt.Sprintf("re_%d", time.Now().UnixNano())}
}
