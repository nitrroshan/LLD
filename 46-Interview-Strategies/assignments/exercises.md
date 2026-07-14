# Chapter 46 — Practice Prompts (Timed Mock Interviews)

This is the capstone — the exercise **is the practice itself.** For each prompt, run the full
**5-step framework** out loud (Clarify → Entities → Relationships → Patterns → Code the core),
ideally with a timer. Don't just design in your head — **narrate** as if an interviewer were
watching. The goal is to make the spine automatic.

**How to run each one (45-min sim):**
1. **Clarify (5m)** — write 3–5 functional use cases + explicit out-of-scope + constraints.
2. **Entities (5m)** — nouns → classes.
3. **Relationships (5m)** — is-a / has-a / uses-a; draw the class diagram.
4. **Patterns (5m)** — name the *force* before each pattern.
5. **Code the core (20m)** — interfaces + key classes + one end-to-end path.
6. **Self-review (5m)** — answer the "extend it" follow-up; list your trade-offs.

---

## Prompt 1 (Easy) — Design a Coffee Vending Machine

Requirements to elicit yourself: select a drink, insert money, dispense, return change; refill
ingredients; out of scope = card payment, persistence.

Must demonstrate:
- **State** for the machine lifecycle (Idle → Selecting → Paid → Dispensing) — Ch25.
- **Strategy or Factory** somewhere justified (e.g., recipe/drink creation).
- One end-to-end path coded: `selectDrink() → insertCoin() → dispense()`.

Follow-up to answer: *"Add a new drink."* Does your design need an `if/switch` edit, or just a
new class? (If it needs a switch — refactor to Factory/registry, Ch03 OCP + Ch44.)

---

## Prompt 2 (Easy/Medium) — Design a Splitwise (expense sharing)

Elicit: add users to a group, add an expense with a split, show each person's net balance;
out of scope = currency conversion, settlement gateway.

Must demonstrate:
- **Strategy** for split type (`EqualSplit`, `ExactSplit`, `PercentSplit`) — the classic force.
- Clean **entities** (`User`, `Group`, `Expense`, `Split`, `BalanceSheet`) with SRP.
- The core algorithm coded: adding an expense updates a balance map; `showBalances()` reads it.

Follow-ups to answer:
- *"Add a new split type (e.g., by shares)."* — should be one new class.
- *"Notify users when added to an expense."* — where does **Observer** slot in?
- Trade-off: store **net balances** vs a full **transaction ledger** — which, and why?

---

## Prompt 3 (Medium) — Design an Elevator System

Elicit: multiple elevators, floor requests (external up/down + internal floor buttons),
scheduling/assignment, direction handling; out of scope = physical motor control.

Must demonstrate:
- **State** for elevator direction/motion (MovingUp / MovingDown / Idle) — Ch25.
- **Strategy** for the **scheduling** algorithm (which elevator serves a request) so it can be
  swapped (nearest-car vs scan) — name the force.
- A `Controller`/`Dispatcher` that assigns requests without becoming a God class (Ch44).
- Core coded: `requestElevator(floor, dir) → dispatcher picks car → car queues stop`.

Follow-ups to answer:
- *"Optimize for rush-hour (all requests from lobby)."* — swap the Strategy, don't rewrite.
- Concurrency (Ch43): multiple requests arrive at once — where's the shared mutable state, and
  how would you guard it?
- Testability (Ch45): how would you test the scheduler deterministically? (Inject the request
  sequence; no wall clock.)

---

## Self-grading rubric (score each run)

Give yourself a check per row — aim for all six before moving to a harder prompt:

- [ ] **Clarified first** — wrote use cases + out-of-scope *before* any class.
- [ ] **Clean decomposition** — SRP classes, good names, no God class.
- [ ] **Abstractions at seams** — interfaces where behavior varies (DIP/OCP).
- [ ] **Pattern justified by a force** — said *why* out loud, didn't force-fit.
- [ ] **Handled the follow-up** — the "add X" extension bent, didn't break.
- [ ] **Narrated trade-offs** — Singleton vs DI, net-balance vs ledger, etc.

**Stretch:** re-run each prompt with a stricter 30-minute timer, and practice *cutting scope out
loud* when you fall behind. That controlled scope-cutting is the strongest senior signal.
