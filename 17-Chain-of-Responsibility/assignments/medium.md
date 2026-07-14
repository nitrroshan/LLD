# Assignment: Support Ticket Escalation (Medium)

## Objective

Build a support-desk system where tickets are escalated through tiers of support staff based on **severity** and **topic**, and combine the Chain of Responsibility with the **Factory Method** (Chapter 05) to construct the right chain for a given department.

## Background

A support ticket arrives with a severity level and a category. Tier-1 agents handle simple, low-severity issues; harder or higher-severity ones escalate to Tier-2 specialists, then to engineering, then to management. Different departments (e.g., "Billing" vs "Technical") need **different chains** — that's where a factory comes in.

## Part 1 — The Request and Handlers

**`Ticket`:**

| Field | Meaning |
|-------|---------|
| `id` | ticket number |
| `severity` | `1` (low) … `5` (critical) |
| `topic` | e.g. `"password"`, `"billing"`, `"outage"` |
| `description` | free text |

**Handler — `SupportHandler`:**

- Holds `next`, a `name`, and a `maxSeverity` it can handle
- `setNext(...)` returns next for fluent chaining
- `handle(Ticket)`: if `ticket.severity <= maxSeverity` **and** `canHandleTopic(ticket)`, resolve it; otherwise escalate to `next`; if no next, print `Ticket #<id> requires manual triage`

**Concrete handlers (one file each):**

| Handler | maxSeverity | Handles topics |
|---------|-------------|----------------|
| `Tier1Support` | 2 | any |
| `Tier2Support` | 3 | any |
| `EngineeringSupport` | 5 | `"outage"`, `"bug"`, `"crash"` |
| `ManagementSupport` | 5 | any (final catch-all) |

> Note: `EngineeringSupport` handles high severity **only** for technical topics; a severity-5 *billing* issue should fall through Engineering to Management. This shows a handler can decline based on **more than one** criterion.

When a handler resolves a ticket, print: `Ticket #<id> [sev <severity>, <topic>] resolved by <name>`.

## Part 2 — Combine with Factory Method (Ch05)

Define a `SupportChainFactory` with a factory method `createChain(String department)` that assembles and returns the **head** of a ready-to-use chain:

| Department | Chain |
|------------|-------|
| `"technical"` | Tier1 → Tier2 → Engineering → Management |
| `"billing"` | Tier1 → Tier2 → Management (no engineering tier) |

The client asks the factory for a chain by department name and never wires handlers manually.

### What to implement

1. `Ticket`, `SupportHandler` (abstract/interface), the 4 concrete handlers
2. `SupportChainFactory` with `createChain(department)`
3. `Main`:
   - Build a `"technical"` chain, submit:
     - sev 1 `"password"` → Tier 1
     - sev 3 `"login"` → Tier 2
     - sev 5 `"outage"` → Engineering
     - sev 5 `"refund"` → falls through to Management
   - Build a `"billing"` chain, submit a sev 4 `"chargeback"` → Management

### Expected Result (shape)

```
--- Technical department ---
Ticket #1 [sev 1, password] resolved by Tier 1 Support
Ticket #2 [sev 3, login] resolved by Tier 2 Support
Ticket #3 [sev 5, outage] resolved by Engineering
Ticket #4 [sev 5, refund] resolved by Management
--- Billing department ---
Ticket #5 [sev 4, chargeback] resolved by Management
```

## Constraints

- One file per class/type in all 4 languages
- The factory hides chain construction — `Main` never calls `setNext` directly
- Each handler decides based on **both** severity and topic where relevant
- Adding a new tier or a new department must not modify existing handlers
- Guarantee no ticket is lost — the final handler is a catch-all

## Stretch Goal (optional)

Add logging so each handler prints `[<name>] escalating ticket #<id>` when it forwards, letting you trace a ticket's full path through the chain.

## Submission

Put your solution in `17-Chain-of-Responsibility/assignments/medium/src/{java,cpp,rust,go}/`.
