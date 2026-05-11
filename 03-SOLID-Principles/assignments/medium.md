# Assignment: Medium — Design a Payment Processing System Using SOLID

## Objective
Design a payment processing system from scratch applying **all 5 SOLID principles**. Combines SOLID with OOP from Chapter 01 and UML from Chapter 02.

## Requirements

Build a system where:
- Users can pay with **CreditCard**, **PayPal**, or **BankTransfer**
- Each payment method has different **validation** rules
- After payment, a **receipt** is generated
- Payments are **logged** to a configurable destination
- Some payment methods support **refunds**, others don't

### Specific Rules

| Method | Validation | Supports Refund? |
|--------|-----------|-----------------|
| CreditCard | Card number must be 16 digits | Yes |
| PayPal | Email must contain "@" | Yes |
| BankTransfer | Account number must be 10+ chars | No |

## Skeleton Files Provided

Fill in the TODO comments in each file under `assignments/medium/src/chapter03/medium/`.

## SOLID Mapping

| Principle | How it applies |
|-----------|---------------|
| SRP | PaymentProcessor only processes; Validator validates; ReceiptGenerator generates |
| OCP | New payment methods = new classes implementing interfaces |
| LSP | All PaymentMethod implementations work correctly when substituted |
| ISP | Refundable is a separate interface — BankTransfer doesn't implement it |
| DIP | PaymentProcessor depends on interfaces (PaymentMethod, Logger), not concretions |

## Expected Output
```
=== Credit Card Payment ===
Validating credit card: 1234567890123456... VALID
Processing $99.99 via CreditCard
[LOG] Payment processed: $99.99 via CreditCard
Receipt: $99.99 paid via CreditCard at 2024-01-01

=== PayPal Payment ===
Validating PayPal: user@email.com... VALID
Processing $49.99 via PayPal
[LOG] Payment processed: $49.99 via PayPal

=== Refund ===
Refunding $99.99 to CreditCard
Refunding $49.99 to PayPal
BankTransfer does not support refunds (won't compile if you try!)

=== Bank Transfer ===
Validating bank transfer: ACC1234567890... VALID
Processing $200.00 via BankTransfer
[LOG] Payment processed: $200.00 via BankTransfer
```

## Compile & Run
```
cd 03-SOLID-Principles/assignments/medium/src
javac chapter03/medium/*.java
java chapter03.medium.Main
```

## Checklist
- [ ] All 5 SOLID principles applied
- [ ] No `if/else` or `instanceof` for payment type selection
- [ ] No `UnsupportedOperationException` — use ISP instead
- [ ] Logger is injected (DIP)
- [ ] New payment methods can be added without modifying existing code (OCP)
- [ ] Code compiles and runs with expected output
