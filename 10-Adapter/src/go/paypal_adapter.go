package main

type PayPalAdapter struct {
	paypal *PayPalApi
}

func NewPayPalAdapter(paypal *PayPalApi) *PayPalAdapter {
	return &PayPalAdapter{paypal: paypal}
}

func (a *PayPalAdapter) ProcessPayment(amount float64, currency string) bool {
	response := a.paypal.SendPayment(float32(amount), currency)
	return response.StatusCode == 0
}

func (a *PayPalAdapter) Refund(transactionId string) bool {
	response := a.paypal.ReversePayment(transactionId)
	return response.StatusCode == 0
}
