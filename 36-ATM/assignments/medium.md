# Chapter 36 — Assignment (Medium)

## Fund transfer + audit log + an Out-of-Service state

A **design + implementation** exercise combining all three patterns of this chapter:
**Command** (a new multi-account transaction), **State** (a new lifecycle state), and a
cross-cutting **audit log**.

### Part A — `TransferTransaction` (Command)

Move money from the authenticated account to another account in the same bank.

Requirements:
- Constructed with the source `Account`, the destination account number, the
  `BankService` (to look up the destination), and an amount.
- `execute()` must:
  - reject if the destination account does not exist,
  - reject if the source has insufficient balance,
  - otherwise **debit the source and credit the destination atomically** (both or
    neither) and print the new source balance.
- No cash is dispensed (this is an internal transfer, not a withdrawal).

Think about ordering: what happens if the credit "fails" after the debit? For this
in-memory version, guarantee both succeed together; in your notes, describe how you'd
make it safe across a real network (idempotency / two-phase commit).

### Part B — Audit log

Every executed transaction should be recorded centrally, regardless of type.

Requirements:
- Introduce an `AuditLog` (a simple appendable list of entries with the account number
  and `transaction.description()`).
- The **ATM records the entry** when it invokes a transaction — i.e., logging happens in
  one place, not scattered inside each command.
- Provide a way to print the full audit trail at the end of the demo.

Design question to answer in a comment or short `DESIGN.md`: should the audit entry be
written **before** or **after** `execute()`, and how do you record whether the
transaction *succeeded*? (Hint: consider having `execute()` return a result, or having
the command expose a status — and note the trade-off.)

### Part C — `OutOfServiceState` (State)

Add a maintenance state.

Requirements:
- A new `ATMState` in which **all customer actions are refused** with a clear message.
- Add an ATM-level way to enter and leave it (e.g., `enterMaintenance()` /
  `exitMaintenance()`), only permitted when no card is inserted.
- While out of service, `insertCard` must be rejected; after `exitMaintenance()`, the
  ATM returns to `Idle` and works normally again.

### Constraints

- `TransferTransaction` and `OutOfServiceState` must be **additive** — no changes to the
  existing transaction classes; minimal, justified changes to `ATM` only for the
  maintenance entry/exit and the audit hook.
- Keep the PIN-security rule: never log or print a PIN.

### Demo (extend `Main` / `main.cpp`)

1. Authenticate on `ACC1`, **transfer** $50 to `ACC2`; verify both balances changed.
2. Attempt a transfer to a non-existent account (rejected) and an over-balance transfer
   (rejected).
3. Put the ATM **out of service**, try to insert a card (rejected), then bring it back
   and complete a normal balance inquiry.
4. Print the **audit log** showing every transaction that ran.

### What good looks like

- Transfer is one new `Transaction`; out-of-service is one new `ATMState`.
- Logging is centralized (one hook), not duplicated in each command.
- A short note on transactional safety (atomic debit+credit; how it generalizes to a
  distributed setting).
