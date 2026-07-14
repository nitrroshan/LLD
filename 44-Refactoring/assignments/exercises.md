# Chapter 44 — Exercises

Refactoring practice. The golden rule: **change structure, not behavior** — keep a demo/test
that produces the *same output* before and after. Refactor in small steps.

---

## Exercise 1 (Easy) — Feel the Open/Closed payoff

Add a new customer tier, **`STUDENT`** (15% discount), to **both** the `before` and the `after`
versions from this chapter.

Requirements:
- In `before`: add the tier. Notice you must **edit the switch** inside `process(...)` (and any
  *other* place that switches on the customer type). Count how many spots you touched.
- In `after`: add a `StudentDiscount` class + one factory case. Count the spots (spoiler: 2, and
  the `OrderProcessor` isn't one of them).
- Write down the difference in a comment: this *is* the Open/Closed Principle — the refactored
  design is **open for extension** (new class) and **closed for modification** (no edits to the
  processor).

What good looks like: a one-line-per-place tally showing the smelly version needs edits in the
processor while the clean version doesn't.

---

## Exercise 2 (Medium) — Refactor a second smelly class

Here is a fresh smell to fix (write it out, then refactor). A `NotificationService` that does
everything:

```
class NotificationService {
  void notify(String channel, String userJson, String message) {
    // 1. parse userJson by hand (primitive obsession)
    // 2. if (channel == "email") { ...smtp... }
    //    else if (channel == "sms") { ...gateway... }
    //    else if (channel == "push") { ...fcm... }         // switch-on-type
    // 3. build the message body inline                     // mixed concern
    // 4. write a log line inline                           // mixed concern
  }
}
```

Requirements:
- Identify **at least four** smells (name them: God class, switch-on-type, primitive obsession,
  mixed concerns, long method…).
- Refactor to: a `Channel`/`Notifier` **Strategy** (Email/Sms/Push), a real `User` type instead
  of raw JSON/strings, a `MessageBuilder` for the body, and a thin `NotificationService`
  orchestrator. (Optionally a `NotifierFactory`.)
- Keep a demo that sends via each channel and prints the same result before and after your
  refactor.

Design questions to answer:
- Which smell did each refactoring step remove, and which **pattern/principle** is the target
  (map them: switch → Strategy, God class → SRP, raw strings → value type)?
- Where would a **Decorator** fit if you later wanted "also log every notification" without
  touching the notifiers?

---

## Exercise 3 (Medium) — Characterization tests first

You've inherited the smelly `OrderProcessorBefore` with **no tests** and must change the tax
rule. Do it safely.

Requirements:
1. Write **characterization tests** that pin the *current* behavior (feed several inputs, assert
   the exact totals it produces now — even if you suspect a bug, capture what it *does*).
2. *Now* refactor toward the clean design, running those tests after every small step — they must
   stay green (behavior preserved).
3. Only *after* the refactor, make the actual change (e.g., a configurable tax rate) as a
   separate step.

Design question to answer: why write tests that pin *possibly-buggy* current behavior before
refactoring? (You're separating "restructure safely" from "fix the bug" — two changes, two steps,
each verifiable.) Tie this to Kent Beck's *"make the change easy, then make the easy change."*

---

## What good looks like
- The same input yields the same output before and after every refactor (behavior preserved).
- Each refactoring step is named and mapped to the smell it removes and the pattern it targets.
- A clear articulation of Open/Closed (Ex 1) and characterization-tests-first (Ex 3).
