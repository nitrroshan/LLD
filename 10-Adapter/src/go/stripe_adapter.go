package main

import "math"

type StripeAdapter struct {
	stripe   *StripeApi
	apiToken string
}

func NewStripeAdapter(stripe *StripeApi, apiToken string) *StripeAdapter {
	return &StripeAdapter{stripe: stripe, apiToken: apiToken}
}

func (a *StripeAdapter) ProcessPayment(amount float64, currency string) bool {
	cents := int(math.Round(amount * 100))
	result := a.stripe.CreateCharge(cents, currency, a.apiToken)
	return result.Success
}

func (a *StripeAdapter) Refund(transactionId string) bool {
	result := a.stripe.CreateRefund(transactionId)
	return result.Success
}
