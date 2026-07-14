# Assignment: Order Processing Workflow (Medium)

## Objective

Model an e-commerce **order lifecycle** with the State pattern, where each state permits only certain actions and transitions — and guards against invalid operations. Combine it with a light **Observer** touch (Ch23) so status changes notify a listener.

## Background

An order moves through a lifecycle: Created → Paid → Shipped → Delivered, with a Cancelled branch. Crucially, *which actions are legal depends on the state*: you can pay a created order but not a shipped one; you can cancel before shipping but not after delivery. State makes each stage enforce its own rules instead of a tangle of `if (status == ...)` checks.

## Requirements

**Context — `Order`:**

Holds an `id`, a `total`, and the current `OrderState`. Public actions delegate to the state:

| Action | Legal in states |
|--------|-----------------|
| `pay()` | Created |
| `ship()` | Paid |
| `deliver()` | Shipped |
| `cancel()` | Created, Paid (NOT Shipped/Delivered) |

Illegal actions print a clear rejection like `Cannot ship an order that isn't paid`.

**State — `OrderState`:** `pay()`, `ship()`, `deliver()`, `cancel()`, `name()`. Each concrete state implements only the legal transitions and rejects the rest.

**Concrete states (one file each):**

| State | Allows | Transitions to |
|-------|--------|----------------|
| `CreatedState` | pay → Paid, cancel → Cancelled | Paid / Cancelled |
| `PaidState` | ship → Shipped, cancel → Cancelled (refund) | Shipped / Cancelled |
| `ShippedState` | deliver → Delivered | Delivered |
| `DeliveredState` | (terminal — all actions rejected) | — |
| `CancelledState` | (terminal — all actions rejected) | — |

## Observer touch (Ch23)

Let `Order` hold one `StatusListener` (an observer / callback) notified on every successful transition: `onStatusChanged(orderId, newStatus)`. In `Main`, attach a listener that logs `Order <id> is now <status>`.

### What to implement

1. `Order`, `OrderState`, and the 5 concrete states
2. A `StatusListener` interface/callback
3. `Main`:
   - Happy path: create → pay → ship → deliver (listener logs each)
   - Illegal path: try to `ship()` a freshly created order → rejected
   - Cancel path: create another order, pay, cancel → Cancelled; then try to `pay()` again → rejected (terminal)

### Expected Result (shape)

```
Order #1 created
  Order #1 is now PAID
  Order #1 is now SHIPPED
  Order #1 is now DELIVERED
Order #2 created
  Cannot ship an order that isn't paid
  Order #2 is now PAID
  Order #2 is now CANCELLED
  Cannot pay a cancelled order
```

## Constraints

- One file per class/type in all 4 languages
- Each state enforces its own legal actions — no central `switch` on status
- Terminal states (Delivered, Cancelled) reject every action with a clear message
- The status listener is notified only on **successful** transitions
- Illegal actions must not change the state

## Design Questions to Answer (in a comment)

1. Why is this **State** and not **Strategy**? (Who drives the transitions, and does the object move through stages over time?)
2. How does State eliminate the `if (status == X)` checks that a naive implementation would scatter across `Order`?

## Stretch Goal (optional)

Add a `history` list on `Order` recording each state entered, and print the full path at the end.

## Submission

Put your solution in `25-State/assignments/medium/src/{java,cpp,rust,go}/`.
