# LLD Interview Prep — Master Plan & Tracker

> **How to use this file:** This is your persistent interview-prep coach plan. Any time you want
> to train, just tell me one of the **trigger phrases** below and I'll run that session using the
> rules here — I'll read this file, pick up where the tracker left off, and log your score back
> into it. You don't need to re-explain anything.
>
> **Trigger phrases:**
> - *"Run interview prep"* → I pick your next session from the tracker and start it.
> - *"Mock interview: <topic>"* → full 45-min timed mock on that prompt.
> - *"Pattern drill"* → rapid-fire pattern recall quiz.
> - *"Grade me"* → I score my last mock against the rubric and log it.
> - *"Where am I?"* → I summarize your progress + weak areas from the tracker.

---

## 0. Readiness goal

You're **interview-ready** when you can, on a cold prompt, in ≤45 min, *out loud*:
1. Clarify scope (use cases + out-of-scope) before coding.
2. Decompose to clean SRP classes with good names.
3. Put abstractions at the seams (DIP/OCP) and justify each pattern by a **force**.
4. Code a compiling core with one end-to-end path.
5. Handle the "how would you extend it?" follow-up without a rewrite.
6. Narrate trade-offs throughout.

**Target:** score **5/6 or 6/6** on the rubric across **3 consecutive** different prompts,
including at least one Advanced prompt, under a 45-min timer. Then: 30-min stretch.

---

## 1. The rubric (score every mock 0–6)

One point each — I'll check these off when grading you:

- [ ] **Clarified first** — use cases + explicit out-of-scope *before* any class.
- [ ] **Clean decomposition** — SRP classes, good names, no God class.
- [ ] **Abstractions at seams** — interfaces where behavior varies (DIP/OCP).
- [ ] **Pattern justified by a force** — said *why*, didn't force-fit.
- [ ] **Extension handled** — the follow-up bent the design, didn't break it.
- [ ] **Trade-offs narrated** — Singleton vs DI, inheritance vs composition, etc.

Recurring dimensions I'll also comment on: **time management** and **thinking aloud**.

---

## 2. The program (4 stages, ~11 sessions)

Work top to bottom. Each session is self-contained (~30–60 min). I drive; you produce the design.

### Stage A — Foundations recall (2 sessions)
Goal: prove the toolkit is instant before doing full mocks.

| # | Session | What I'll do | Trigger |
|---|---------|--------------|---------|
| A1 | **Pattern-recall drill** | I give you 15 real-world cues ("multiple pricing schemes", "one instance"); you name the pattern + which chapter + one-line why. | *"Pattern drill"* |
| A2 | **SOLID + design-smell drill** | I show 5 smelly snippets; you name the smell (Ch44) + violated principle (Ch03) + the fix. | *"Run interview prep"* (I'll pick A2) |

### Stage B — Guided mocks (3 sessions, hints allowed)
Goal: internalize the **5-step framework**. I coach mid-way if you stall.

| # | Prompt | Core patterns | Trigger |
|---|--------|---------------|---------|
| B1 | **Vending Machine** | State, Strategy/Factory | *"Mock interview: vending machine"* |
| B2 | **Splitwise** | Strategy (split), Observer | *"Mock interview: splitwise"* |
| B3 | **Parking Lot** | Strategy, Factory, Singleton | *"Mock interview: parking lot"* |

Rules: 45-min soft timer, I may nudge you if you skip clarification or go silent. I grade at the end.

### Stage C — Realistic mocks (4 sessions, no hints)
Goal: perform solo. I stay quiet until you say "done", then grade hard.

| # | Prompt | Core patterns | Trigger |
|---|--------|---------------|---------|
| C1 | **Elevator System** | State, Strategy (scheduling), concurrency | *"Mock interview: elevator"* |
| C2 | **Notification Service** | Observer, Strategy, Factory | *"Mock interview: notification service"* |
| C3 | **LRU/LFU Cache** | Strategy (eviction), Proxy, concurrency | *"Mock interview: cache"* |
| C4 | **Ride-Sharing / Uber** | Strategy, State, Observer, Proxy | *"Mock interview: ride sharing"* |

Rules: strict 45-min timer, **no hints**. If you fall behind, I want to see you *cut scope out loud*.

### Stage D — Stretch & polish (2 sessions)
Goal: senior signal under pressure.

| # | Session | What I'll do | Trigger |
|---|---------|--------------|---------|
| D1 | **30-min speed mock** | A fresh prompt (I'll pick: Chess / Food Delivery / Tic-Tac-Toe) on a tight 30-min timer. | *"Run interview prep"* (I'll pick D1) |
| D2 | **Weak-area targeted mock** | I pick a prompt that hits whatever the tracker shows as your lowest rubric rows. | *"Run interview prep"* (I'll pick D2) |

---

## 3. How I run a mock (so you know what to expect)

1. I present the **prompt only** (vague, like a real interviewer).
2. **You** talk through: Clarify → Entities → Relationships (rough class diagram) → Patterns
   (name the force) → Core code (interfaces + key classes + one end-to-end path). Type it out
   like you'd say/whiteboard it.
3. In **Stage B** I may interject hints; in **Stage C/D** I stay silent until you say **"done"**.
4. I then ask **1–2 follow-ups** ("add feature X", "make it concurrent", "how would you test it?").
5. I **grade** against the rubric (0–6), give specific feedback, and **log it in the tracker below**.

---

## 4. Progress tracker

I update this after each session. `—` = not attempted.

| Session | Date | Score /6 | Time | Weak rows to fix | Notes |
|---------|------|----------|------|------------------|-------|
| A1 Pattern drill | — | — | — | — | — |
| A2 SOLID/smell drill | — | — | — | — | — |
| B1 Vending Machine | — | — | — | — | — |
| B2 Splitwise | — | — | — | — | — |
| B3 Parking Lot | — | — | — | — | — |
| C1 Elevator | — | — | — | — | — |
| C2 Notification Service | — | — | — | — | — |
| C3 Cache | — | — | — | — | — |
| C4 Ride-Sharing | — | — | — | — | — |
| D1 Speed mock (30m) | — | — | — | — | — |
| D2 Weak-area mock | — | — | — | — | — |

**Rubric-row heat map** (tally of misses per row — I fill this in to spot patterns):

| Rubric row | Times missed |
|------------|--------------|
| Clarified first | 0 |
| Clean decomposition | 0 |
| Abstractions at seams | 0 |
| Pattern justified by force | 0 |
| Extension handled | 0 |
| Trade-offs narrated | 0 |

---

## 5. Prompt bank (extra reps if you exhaust the plan)

Mapped to the chapters that carry them — pick any and say *"Mock interview: <name>"*.

| Prompt | Core patterns | Chapter |
|--------|---------------|---------|
| Tic-Tac-Toe | State, Strategy, Factory | 38 |
| Chess | State, Strategy, Factory | 38 |
| Food Delivery | Strategy, Observer, State | 40 |
| Logging Framework | Chain of Responsibility, Strategy, Singleton | 41 |
| Snake & Ladder | State/turn mgmt, Factory | — |
| Rate Limiter | Strategy (token bucket/sliding window), Singleton | — |
| Text Editor (undo) | Command, Memento | 17 |
| In-memory Key-Value Store | Strategy, Proxy, concurrency | 42 |
| Movie Ticket Booking | State (seat lock), Strategy (pricing), Observer | — |
| Online Auction | Observer, State, Strategy | — |

---

## 6. Quick reference (don't peek during a mock)

- **5-step framework:** Clarify → Entities → Relationships → Patterns → Code core. (Ch46)
- **Cue → pattern cheat sheet:** see [46-Interview-Strategies/notes.md](46-Interview-Strategies/notes.md).
- **Time budget (45m):** 5 clarify / 10 entities+diagram / 20 patterns+core / 10 follow-ups.
- **Testability reflex:** inject a `Clock`, program to interfaces (Ch45).
- **Refactor reflex:** switch-on-type → Strategy/State; God class → Extract Class (Ch44).
