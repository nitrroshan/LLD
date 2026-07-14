# Chapter 36 — Assignment (Easy)

## Add two new transaction types: Mini-Statement and PIN Change

This is a **design + implementation** exercise. It reinforces the **Command** pattern:
new transactions must be *additive* — you should not modify `ATM`, `ATMState`, or any
existing transaction to add them.

### Background

The ATM already supports `WithdrawTransaction`, `DepositTransaction`, and
`BalanceInquiryTransaction` — all implementing the `Transaction` (Command) interface,
invoked uniformly by the `AuthenticatedState` via `performTransaction(...)`.

### Requirements

1. **`MiniStatementTransaction`**
   - Prints the last *N* (e.g., 5) transactions performed on the account.
   - To support this, give `Account` a small **transaction history** (a capped list of
     short strings like `"Withdraw $180"`, `"Deposit $100"`). Have the existing
     withdraw/deposit commands append to it on success.
   - `execute()` prints the most recent entries (newest first). If there is no history,
     print a friendly "No recent transactions" message.

2. **`ChangePinTransaction`**
   - Constructed with the old PIN and the new PIN.
   - `execute()` verifies the old PIN against the account; on success updates the PIN,
     on failure prints an error and does **not** change anything.
   - Add a `changePin(oldPin, newPin)` method to `Account` (keep the PIN check inside
     the account — the transaction should not read the stored PIN directly).

### Constraints

- **Do not modify** `ATM`, `ATMState`, `IdleState`, `HasCardState`, or
  `AuthenticatedState`. If you find yourself editing them, your Command wiring is wrong.
- Both new classes implement `Transaction` and are passed to
  `atm.performTransaction(...)` exactly like the existing ones.
- Keep money as whole dollars; keep the security rule in mind — never print a PIN.

### Demo (add to `Main` / `main.cpp`)

- Authenticate, do a withdraw and a deposit, then run a **mini-statement** and confirm
  both appear.
- Run a **PIN change** with the wrong old PIN (rejected), then the correct old PIN
  (accepted); eject, re-insert, and authenticate with the **new** PIN to prove it worked.

### What good looks like

- Zero changes to the state machine or the ATM context.
- `Account` owns its own history and PIN rules (encapsulation).
- Adding each transaction was *only* a new `Transaction` class — that's the Command
  pattern paying off.

### Stretch (optional)

- Add an **audit log**: have the ATM record every executed `Transaction.description()`
  to a list, independent of the account history. (This previews the medium assignment.)
