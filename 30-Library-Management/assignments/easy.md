# Assignment: Digital Books + Renewals (Design + Code)

## Objective

Extend the library with **digital copies** (unlimited simultaneous loans, auto-expiry) and **loan renewals**, exercising the entity split and policy design. Implement in **Java and C++**.

## New Requirements

1. **Digital books** — a title can have digital copies that don't run out: any number of members may "borrow" a digital copy at once, and it **auto-returns** after the loan period (no physical handoff, no reservations needed).
2. **Renewals** — a member may renew an active loan once, extending the due date by the member's loan period — **unless** another member has reserved that title (then renewal is refused).

## Design Tasks (answer in `DESIGN.md`)

1. **Where do digital books fit?** Options: a `DigitalBookItem` subtype of `BookItem` whose `findAvailable` never runs out, or a separate `DigitalBook` type. Which keeps `Library.borrowBook` cleanest, and why? Consider the Liskov Substitution Principle.
2. **Renewal rules** — where does the "can this be renewed?" check live (the `Loan`, the `Member`, or the `Library`)? It depends on reservations, so justify with Single Responsibility.
3. Does adding digital books force changes to the **fine** logic? (Digital loans usually can't be overdue — how do you express that?)

## Implementation Requirements

- Add `DigitalBookItem` (or `DigitalBook`) so borrowing a digital title always succeeds and records an auto-expiry day.
- Add `Library.renewLoan(barcode, day)` that extends the due date if allowed (no pending reservation for the title), else prints a refusal.
- A digital loan's return/expiry incurs **no fine**.
- Update the demo: two members borrow the same digital title at once; renew a physical loan successfully, then fail a renewal because someone reserved it.

## Constraints

- One file per class/type in **Java and C++**
- Reuse the existing `Book`/`BookItem` split — don't fork a parallel hierarchy
- Renewal and digital-availability logic must not scatter `if (isDigital)` checks across `Library` — prefer polymorphism
- Adding these features should not modify the `FineStrategy` classes

## Submission

Put your solution in `30-Library-Management/assignments/easy/src/{java,cpp}/` with a short `DESIGN.md`.
