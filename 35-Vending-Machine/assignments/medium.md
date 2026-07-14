# Assignment: Low-Stock Observer + Configurable Coin/Payment Sets (Design + Code)

## Objective

Add **inventory notifications** (Observer) and make the accepted **coins** and **payment methods** fully configurable — showing the machine as an assembly of independent, swappable parts. Implement in **Java and C++**.

## Part 1 — Inventory Observer (Ch23)

Add an `InventoryObserver` notified when:
- a product's stock drops to a **low threshold** (e.g., ≤ 1), and
- a product goes **out of stock**.

Concrete observers:
- `MaintenanceAlert` — prints a restock alert.
- `SalesTracker` — counts units sold per product.

The `Inventory` (or machine) notifies observers on each successful dispense.

## Part 2 — Configurable Coin & Payment Sets

- Build the coin-acceptor **chain from a configured list** of accepted denominations (a factory/builder that assembles `CoinHandler`s), so a machine in another region accepts different coins without code changes.
- Register available `PaymentStrategy` methods (card, UPI, wallet) in a map keyed by name; the user picks one by name at pay time.

## Design Tasks (answer in `DESIGN.md`)

1. Should the **machine** or the **inventory** own the observer list? Who has the authoritative moment "a unit was sold"? Justify with SRP.
2. Assembling the coin chain from config is a small **Factory/Builder**. Why is that better than hard-coding `new NickelHandler().setNext(...)`? What does it enable operationally?
3. You now have four plug-in axes: **states** (State), **coin acceptance** (Chain of Responsibility), **payment** (Strategy), **notifications** (Observer). Explain how each keeps `VendingMachine` small and closed for modification.

## Implementation Requirements

- `InventoryObserver` + `MaintenanceAlert` + `SalesTracker`; notify on low-stock and out-of-stock at dispense time.
- A `CoinChainBuilder` (or factory) that assembles the chain from a list of `Coin`s.
- A registry of named `PaymentStrategy`s; `payWith(methodName)`.
- Demo: sell until an item hits low stock (alert fires) and then out of stock; build a machine accepting a custom coin set; pay via a strategy chosen by name.

## Constraints

- One file per class/type in **Java and C++**
- Adding an observer, a coin denomination, or a payment method must not modify `VendingMachine` (OCP)
- The four pattern axes stay independent — no cross-entanglement
- Notifications fire only on **successful** dispense

## Design Question to Answer

This machine is a case study in **composing patterns**: State + Chain of Responsibility + Strategy + Observer + Factory. Pick any two and explain how they interact at runtime (e.g., how a coin flows through the chain *inside* the AwaitingPayment state, then triggers a dispense that notifies observers).

## Submission

Put your solution in `35-Vending-Machine/assignments/medium/src/{java,cpp}/` with a short `DESIGN.md`.
