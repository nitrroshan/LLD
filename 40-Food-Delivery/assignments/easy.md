# Chapter 40 — Assignment (Easy)

## Add a NetBanking payment method + a restaurant-reject transition

A **design + implementation** exercise reinforcing **Factory** and **State**. Both additions
must be *additive* — no rewrite of the order flow or existing states.

### Part A — `NetBankingPayment` (Factory)

Add a fifth payment option.

Requirements:
- Add a `NETBANKING` value to `PaymentType` and a `NetBankingPayment` implementing
  `PaymentMethod`.
- Add the one `case` to `PaymentFactory.create(...)`.
- **Nothing in the ordering flow changes** — `placeOrder` still just calls
  `paymentMethod.pay(total)`. Prove it by placing an order with `PaymentType.NETBANKING`.

Design question to answer: adding a payment method touched exactly two places (the enum + the
factory). Explain how the Factory keeps that change from leaking into `FoodDeliveryService`,
and contrast with what a `switch` inside `placeOrder` would have required.

### Part B — Restaurant reject (State)

A restaurant can reject a freshly placed/confirmed order (out of stock, too busy).

Requirements:
- Add a `reject()` action. Two clean options — pick one and justify:
  - add `reject(Order)` to the `OrderState` interface (every state answers it), or
  - add a `RejectedState` and a `Order.reject()` that only the early states honor.
- Rejection is legal **only from `Placed` or `Confirmed`** (before the kitchen starts). From
  `Preparing` onward it must be refused — same spirit as the existing "cancel only before
  preparing" rule.
- On reject: transition to a terminal state (`Cancelled` or a new `Rejected`), **refund** the
  payment (print a refund line), and notify all observers.

### Constraints

- The new payment method is **one class + one factory case**; `FoodDeliveryService` is
  untouched by it.
- Reject is **additive** to the state machine; don't weaken the transition rules of existing
  states.

### Demo (extend `Main` / `main.cpp`)

1. Place an order paying by **NetBanking** and run it end to end.
2. Place an order, have the restaurant **reject** it from `Confirmed` (show the refund + the
   terminal state); then try to reject an order that's already `Preparing` and show it's
   refused.

### What good looks like

- NetBanking slotted in via the Factory with zero change to the order flow.
- Reject is a legal transition only from the early states; later states refuse it.
- A clear explanation of why the Factory localized the payment change.
