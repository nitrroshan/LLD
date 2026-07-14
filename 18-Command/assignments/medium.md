# Assignment: Bank Transaction System with Undo (Medium)

## Objective

Use the Command pattern to model **bank transactions** as objects with **stateful undo**, and support a full multi-level undo history.

## Background

Deposits and withdrawals change an account balance. To undo them correctly, each command must remember enough to reverse its effect. A withdrawal that was **rejected** (insufficient funds) must undo to a **no-op**, not accidentally credit the account. This is where naive undo goes wrong — the command must capture what actually happened.

## Requirements

**Receiver — `Account`:**

| Method | Behavior |
|--------|----------|
| `getBalance()` | current balance |
| `deposit(amount)` | adds to balance |
| `withdraw(amount)` | subtracts **only if** sufficient funds; returns `true`/`false` for success |

**Command interface — `Transaction`:** `execute()`, `undo()`

**Concrete commands (one file each):**

| Command | execute() | undo() |
|---------|-----------|--------|
| `DepositTransaction` | deposit `amount` | withdraw `amount` back |
| `WithdrawTransaction` | try to withdraw `amount`; **remember whether it succeeded** | if it succeeded, deposit `amount` back; if it failed, **do nothing** |

**Invoker — `TransactionManager`:**

- `execute(Transaction t)` — runs it and pushes onto an undo history
- `undo()` — pops the last transaction and undoes it
- `undoAll()` — undoes everything back to the start

### What to implement

1. `Account`, `Transaction`, `DepositTransaction`, `WithdrawTransaction`, `TransactionManager`
2. `Main`:
   - Start balance $100
   - Deposit $50 → $150
   - Withdraw $200 → **rejected**, still $150
   - Withdraw $80 → $70
   - Print balance, then `undoAll()` → back to $100

### Expected Result (shape)

```
Start: $100
Deposit $50  -> $150
Withdraw $200 -> REJECTED ($150)
Withdraw $80 -> $70
Balance: $70
--- Undo all ---
Undo withdraw $80 -> $150
Undo rejected withdraw -> $150 (no change)
Undo deposit $50 -> $100
Final: $100
```

## Constraints

- One file per class/type in all 4 languages
- `WithdrawTransaction.undo()` must be a **no-op** if the original withdrawal was rejected — capture the outcome in `execute()`
- `TransactionManager` depends only on the `Transaction` interface
- Undo must handle an empty history gracefully

## Stretch Goal (optional)

Add **redo**: keep a second stack of undone transactions and re-execute the most recent one on `redo()`.

## Submission

Put your solution in `18-Command/assignments/medium/src/{java,cpp,rust,go}/`.
