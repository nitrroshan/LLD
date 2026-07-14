# Assignment: Sorting Strategies (Easy)

## Objective

Apply the Strategy pattern to sort a list of numbers using **interchangeable comparison strategies**, swapped at runtime — the same idea as Java's `Comparator`.

## Background

Sorting order is a classic strategy: the *algorithm* to compare two elements varies (ascending, descending, by absolute value), but the sorting *machinery* stays the same. Instead of writing three sort methods, you write one sorter that delegates comparison to a pluggable strategy.

## Requirements

**Strategy — `SortStrategy`:**

| Method | Returns |
|--------|---------|
| `compare(int a, int b)` | negative if `a` should come before `b`, positive if after, 0 if equal |

**Concrete strategies (one file each):**

| Strategy | Order |
|----------|-------|
| `AscendingStrategy` | smallest → largest |
| `DescendingStrategy` | largest → smallest |
| `ByAbsoluteValueStrategy` | by `|value|`, smallest magnitude first |

**Context — `NumberSorter`:**

| Method | Behavior |
|--------|----------|
| `setStrategy(SortStrategy)` | choose the comparison strategy |
| `sort(list)` | sort a copy of the list using the current strategy and return/print it (a simple bubble/insertion sort using `strategy.compare` is fine) |

### What to implement

1. `SortStrategy`, the 3 concrete strategies, `NumberSorter` — one file per type in all 4 languages
2. `Main`:
   - Input `[3, -1, 4, -1, 5, -9, 2, -6]`
   - Sort ascending, then descending, then by absolute value — swapping the strategy each time on the **same** sorter

### Expected Output (shape)

```
Ascending:  [-9, -6, -1, -1, 2, 3, 4, 5]
Descending: [5, 4, 3, 2, -1, -1, -6, -9]
By |value|: [-1, -1, 2, 3, 4, 5, -6, -9]
```

## Constraints

- One file per class/type
- `NumberSorter` contains the sort loop **once**; only the comparison is pluggable
- Adding a new order (e.g., even-numbers-first) must not modify `NumberSorter`
- If your language supports it, show that a **lambda/closure/function** can also serve as a `SortStrategy` (bonus in `Main`)

## Submission

Put your solution in `22-Strategy/assignments/easy/src/{java,cpp,rust,go}/`.
