package main

import "fmt"

// In Go, lowercase = private, Uppercase = public (exported)

type BankAccount struct {
	owner   string
	balance float64
}

func NewBankAccount(owner string, initialBalance float64) *BankAccount {
	return &BankAccount{owner: owner, balance: initialBalance}
}

func (b *BankAccount) GetBalance() float64 { return b.balance }
func (b *BankAccount) GetOwner() string    { return b.owner }

func (b *BankAccount) Deposit(amount float64) {
	if amount <= 0 {
		fmt.Println("Deposit amount must be positive.")
		return
	}
	b.balance += amount
	fmt.Printf("%s deposited %.1f. New balance: %.1f\n", b.owner, amount, b.balance)
}

func (b *BankAccount) Withdraw(amount float64) {
	if amount <= 0 {
		fmt.Println("Withdrawal amount must be positive.")
		return
	}
	if amount > b.balance {
		fmt.Printf("Insufficient funds! %s tried to withdraw %.1f but balance is %.1f\n",
			b.owner, amount, b.balance)
		return
	}
	b.balance -= amount
	fmt.Printf("%s withdrew %.1f. New balance: %.1f\n", b.owner, amount, b.balance)
}
