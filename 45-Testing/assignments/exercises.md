# Chapter 45 — Exercises

Testing practice. The theme: **testable design == good design.** If a unit is hard to test,
that's a design smell — fix the design, don't just wrestle the test. Use the tiny assert
harness from this chapter (or JUnit/GoogleTest if installed).

---

## Exercise 1 (Easy) — Test with a stub and a spy

Write tests for the `OrderService` from this chapter (the DI version that takes a
`PaymentGateway` and a `Clock`).

Requirements:
- Use a **stub** `Clock` — the `FixedClock` — so the timestamp is deterministic; assert the
  order's recorded time equals the fixed value.
- Use a **spy** `PaymentGateway` — the `FakePaymentGateway` — and after `checkout(...)`, assert
  it recorded **exactly one** charge for the **correct amount** (interaction verification, not
  just the return value).
- Add a test where the fake gateway is configured to **fail** the charge, and assert
  `checkout` handles it (no order recorded / returns the failure).

Design question to answer: what's the difference between a **stub** (feeds canned input — the
clock) and a **spy** (records calls so you can verify them — the gateway)? When do you assert on
the **return value** vs on the **interaction**?

---

## Exercise 2 (Easy/Medium) — Make an untestable class testable

Here is a class riddled with hidden dependencies. Refactor it so it can be unit-tested, then
write the tests.

```
class SignupService {
  boolean register(String email) {
    if (new EmailValidator().isValid(email)) {          // new inside method
      String id = UUID.randomUUID().toString();         // non-deterministic
      long ts = System.currentTimeMillis();             // non-deterministic (wall clock)
      Database.getInstance().save(email, id, ts);       // singleton + real DB
      EmailClient.send(email, "welcome");               // static call, real network
      return true;
    }
    return false;
  }
}
```

Requirements:
- Identify every **seam** that blocks testing (there are ~5).
- Refactor to **inject** them: a `Clock`, an `IdGenerator`, a `UserRepository` (interface), and a
  `Mailer` (interface). Validation can stay or be injected.
- Write tests using **fakes/spies**: a `FixedClock`, a `FixedIdGenerator`, an in-memory
  `FakeUserRepository`, and a spy `Mailer` that records the "welcome" send.
- Assert: a valid email is saved with the fixed id + time **and** the welcome mail was sent
  exactly once; an invalid email does neither.

Design question to answer: each hidden dependency you removed maps to a testability
anti-pattern from §2 (new-inside-method, singleton, static call, wall clock, randomness). Name
the pair for each, and note how the refactor also improved the *design* (DIP/SRP), not just the
tests.

---

## Exercise 3 (Medium) — Test the patterns: Strategy + Observer

Reuse the discount **Strategy** and an **Observer** target from the course.

Requirements:
- **Strategy (parameterized):** write a data-driven test that runs the *same* assertion across
  all discount strategies — `(Regular, 200) -> 0`, `(Premium, 200) -> 20`, `(Vip, 200) -> 40`.
  One test body, a table of cases. (In JUnit this is `@ParameterizedTest`; with the hand-rolled
  harness, loop over a list of cases.)
- **Observer (interaction):** given a subject (e.g., an order/event source) and a **spy
  observer**, fire an event and assert the spy was notified with the expected payload — and that
  an **unsubscribed** observer is **not** notified.

Design questions to answer:
- Why is polymorphic Strategy code so easy to test (each strategy is a pure function with no
  hidden state)? Tie this back to Ch44 — replacing a `switch` with Strategy also made it
  **testable** per-case.
- For the Observer, why do you verify the **interaction** (was `onEvent` called with X) rather
  than an internal field? (Testing observable behavior, not implementation.)

---

## What good looks like
- Deterministic tests: a `FixedClock`/`FixedIdGenerator` removes wall-clock and randomness.
- Interaction verification with spies where the behavior *is* the side effect (charge, mail,
  notify), and value assertions where the behavior *is* the return.
- A clear articulation that every testability fix was also a **design** improvement (DIP/SRP),
  and that Strategy/Observer are trivially testable *because* they depend on abstractions.
