# Assignment: Change-Making + Maintenance State (Design + Code)

## Objective

Make change **realistically** (return actual coins) and add a **Maintenance** state that takes the machine offline, deepening the Strategy and State usage. Implement in **Java and C++**.

## New Requirements

1. **Change-making** — instead of just reporting the change amount, compute the **coins to return** from the machine's coin float. Model this as a `ChangeStrategy`:
   - `GreedyChangeStrategy` — largest-denomination-first (may fail if the float lacks the right coins).
   - Track a **coin float** (how many of each coin the machine holds); dispensing change reduces it, accepted coins increase it.
   - If exact change can't be made, refuse the sale before dispensing and refund.
2. **Maintenance state** — an operator can put the machine into `MaintenanceState` (restock, collect cash). In this state, normal user actions are refused; only `exitMaintenance()` returns it to `Idle`.

## Design Tasks (answer in `DESIGN.md`)

1. Where does the **coin float** live — the machine, the `ChangeStrategy`, or a `CoinBank`? Justify with Single Responsibility, and explain how the change strategy reads/updates it without owning it.
2. `MaintenanceState` is a new state. Which transitions lead in and out of it, and why must user actions be refused there? Confirm no existing state changes.
3. "Can't make exact change" must abort the sale **before** dispensing. Which state detects this, and how do you unwind cleanly (refund inserted coins)?

## Implementation Requirements

- A `CoinBank` (float) + `ChangeStrategy` (`GreedyChangeStrategy`); dispensing returns actual coins or aborts+refunds if impossible.
- `MaintenanceState` with enter/exit; accepted coins and restock update the bank.
- Demo: a purchase that returns specific change coins; a purchase that fails for lack of change; entering maintenance to restock, then exiting.

## Constraints

- One file per class/type in **Java and C++**
- Adding `MaintenanceState` or a new `ChangeStrategy` must not modify existing states (OCP)
- Change logic must not be scattered across states — encapsulate it in the strategy/bank
- Money stays in integer cents

## Submission

Put your solution in `35-Vending-Machine/assignments/easy/src/{java,cpp}/` with a short `DESIGN.md`.
