# Assignment: Settle Up + Shares Split (Design + Code)

## Objective

Add a **settle-up** operation (a user pays off a debt) and a new **split-by-shares** rule, exercising the balance sheet and Strategy. Implement in **Java and C++**.

## New Requirements

1. **Settle up** — `group.settleUp(from, to, amount)` records that `from` paid `to` real money, reducing their debt. It must net correctly (over-payment flips the direction) and notify observers.
2. **Shares split** — a `SharesSplitStrategy` where each participant is assigned an integer number of shares (e.g., Alice 2, Bob 1, Carol 1 → Alice pays half). Splits are `total × userShares / totalShares`, with rounding handled so the shares sum exactly to the total.

## Design Tasks (answer in `DESIGN.md`)

1. Is `settleUp` just a reverse `addDebt`, or does it deserve its own method/event? What does an observer need to distinguish an **expense** from a **payment**?
2. `SharesSplitStrategy` is a fourth split rule. Confirm that adding it required **zero** changes to `Group` or `BalanceSheet` — and explain why (which pattern, which principle).
3. Rounding: with shares (or equal split among 3), cents don't divide evenly. Where should the remainder go, and how do you guarantee the splits always sum to the exact total?

## Implementation Requirements

- `SharesSplitStrategy(Map<userId, shares>)`.
- `Group.settleUp(from, to, amount)` reusing the balance-sheet netting; emit a distinct notification (payment, not expense).
- Demo: run the chapter's expenses, then have the biggest debtor **settle up** part of their debt and show the updated balances + simplified settlements.

## Constraints

- One file per class/type in **Java and C++**
- Adding the shares strategy must not modify `Group`/`BalanceSheet` (OCP)
- Settle-up must net correctly and never produce a negative debt
- Splits must always sum to the exact total (handle rounding)

## Submission

Put your solution in `34-Splitwise/assignments/easy/src/{java,cpp}/` with a short `DESIGN.md`.
