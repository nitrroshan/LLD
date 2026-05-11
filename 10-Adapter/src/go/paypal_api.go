package main

import (
	"fmt"
	"time"
)

// Third-party PayPal API — different interface, amounts as float32.
type PayPalApi struct{}

type PayPalResponse struct {
	StatusCode int // 0 = success
	PaymentId  string
}

func (p *PayPalApi) SendPayment(amount float32, currencyCode string) PayPalResponse {
	fmt.Printf("  [PayPal] Sending %.2f %s\n", amount, currencyCode)
	return PayPalResponse{StatusCode: 0, PaymentId: fmt.Sprintf("PAY-%d", time.Now().UnixNano())}
}

func (p *PayPalApi) ReversePayment(paymentId string) PayPalResponse {
	fmt.Printf("  [PayPal] Reversing payment %s\n", paymentId)
	return PayPalResponse{StatusCode: 0, PaymentId: fmt.Sprintf("REV-%d", time.Now().UnixNano())}
}
