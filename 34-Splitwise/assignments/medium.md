# Assignment: Multi-Currency + Simplification Strategies (Design + Code)

## Objective

Support **multiple currencies** and make **debt simplification pluggable** via a Strategy, so the group can trade off "fewest transactions" against "preserve who-actually-owes-whom". Implement in **Java and C++**.

## Part 1 — Multi-Currency

- Attach a `Currency` (e.g., USD, EUR) to each `Expense`.
- The `BalanceSheet` must convert to a **base currency** using an injected `ExchangeRateProvider` before netting, so balances are comparable.
- Design the conversion boundary so the rest of the system stays currency-agnostic (convert on the way into the balance sheet; store base-currency amounts).

## Part 2 — Pluggable Simplification (Strategy)

Extract simplification into a `SimplificationStrategy`:

| Strategy | Goal |
|----------|------|
| `MinCashFlowStrategy` | fewest total settlements (the current greedy min-cash-flow) |
| `PreserveDirectDebtsStrategy` | keep existing direct debts, only net exact opposites (no re-routing through third parties) |

`Group.simplify(strategy)` delegates to the chosen strategy — swapping it must not change `Group` or `BalanceSheet`'s data.

## Design Tasks (answer in `DESIGN.md`)

1. **Where does currency conversion belong?** In `Expense`, `BalanceSheet`, or a boundary service? Justify keeping the netting logic currency-free.
2. Simplification is now a **Strategy** operating on the balance graph. What minimal read-only view of the balances does it need, so it doesn't couple to `BalanceSheet`'s internals?
3. `MinCashFlowStrategy` can reroute debt through people who weren't in the original transaction (A→C instead of A→B→C). Some users dislike that. How does `PreserveDirectDebtsStrategy` respect that preference, and what does it cost (more transactions)?

## Implementation Requirements

- `Currency` + `ExchangeRateProvider`; `Expense` carries a currency; balances stored in a base currency.
- `SimplificationStrategy` + `MinCashFlowStrategy` + `PreserveDirectDebtsStrategy`; `Group.simplify(strategy)`.
- Demo: add expenses in two currencies, show base-currency balances, then simplify with **both** strategies and compare the settlement lists.

## Constraints

- One file per class/type in **Java and C++**
- Netting logic stays currency-agnostic (convert at the boundary)
- Adding a currency or a simplification strategy must not modify `Group`'s core flow (OCP)
- Both simplification strategies operate on the same balance data via a read-only view

## Design Question to Answer

Splitwise now composes three plug-in axes — **split rules** (Strategy), **notifications** (Observer), **simplification** (Strategy) — around a **Mediator** (`Group`). Explain how the Mediator keeps members decoupled while these three axes stay independently extensible.

## Submission

Put your solution in `34-Splitwise/assignments/medium/src/{java,cpp}/` with a short `DESIGN.md`.
