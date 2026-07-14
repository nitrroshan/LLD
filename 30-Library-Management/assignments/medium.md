# Assignment: Pluggable Search + Per-Type Fine Policy (Design + Code)

## Objective

Make **search** pluggable (by different criteria and ranking) and make **fines depend on member type** — deepening Strategy usage and showing how to keep policies open for extension. Implement in **Java and C++**.

## Part 1 — Search Strategy

Introduce a `SearchStrategy` so the library can search by different criteria without changing `Library`:

| Strategy | Matches on |
|----------|-----------|
| `TitleSearchStrategy` | title substring |
| `AuthorSearchStrategy` | author substring |
| `CombinedSearchStrategy` | title OR author (the current behavior) |

`Library.search(query)` delegates to the current `SearchStrategy`, which is swappable at runtime. Optionally return results **ranked** (e.g., exact-prefix matches first).

## Part 2 — Per-Type Fine Policy

Fines should differ by member type — e.g., students get a **grace period** and a low rate; faculty pay a flat higher rate. Decide how to combine this with the existing `FineStrategy`:

- Option A: the `Member` supplies its own `FineStrategy` (composition), and the library uses `loan.member().fineStrategy()`.
- Option B: a `FineStrategy` that takes the member (or member type) into account.

Pick one, justify it, and implement so that **adding a new member type with its own fine rule requires no change to `Library`**.

## Design Tasks (answer in `DESIGN.md`)

1. Why is search a **Strategy** and not just an overloaded method or a parameter? When does the Strategy pay off?
2. For per-type fines, compare **Option A (member owns a strategy)** vs **Option B (strategy is member-aware)**. Which better respects Open/Closed and why?
3. You now have *two* independent Strategy axes (search, fine). Does either one belong on the `Member`, the `Library`, or a separate policy object? Justify each.

## Implementation Requirements

- `SearchStrategy` + `TitleSearchStrategy`, `AuthorSearchStrategy`, `CombinedSearchStrategy`; `Library` delegates and can swap at runtime.
- Per-type fines via your chosen option; a student and a faculty member returning equally-overdue books are charged **differently**.
- The demo: search the same query with two different search strategies (different results); return overdue books as a student vs a faculty member and show different fines.

## Constraints

- One file per class/type in **Java and C++**
- Adding a new search criterion or a new member fine rule must not modify `Library` (OCP)
- Keep the two Strategy axes independent — search policy and fine policy must not entangle
- No `if (memberType == ...)` fine branching inside `Library`

## Stretch Goal (optional)

Add a `MembershipTierDecorator` (Ch13) that wraps a `FineStrategy` to apply a loyalty discount, showing Strategy + Decorator composing.

## Submission

Put your solution in `30-Library-Management/assignments/medium/src/{java,cpp}/` with a short `DESIGN.md`.
