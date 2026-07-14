# Assignment: Calculator with Undo (Easy)

## Objective

Apply the Memento pattern to a calculator that supports **multi-level undo** by snapshotting its running total before each operation.

## Background

A calculator holds a running result. Each operation (add, subtract, multiply) changes it. To undo, you snapshot the result **before** each operation and restore the most recent snapshot on undo. The undo history knows nothing about *how* the number was computed — it just holds sealed snapshots.

## Requirements

**Memento — `CalculatorMemento`:** immutable snapshot of the result (a single number) plus an optional `label` describing the operation.

**Originator — `Calculator`:**

| Method | Behavior |
|--------|----------|
| `add(double n)` | result += n |
| `subtract(double n)` | result -= n |
| `multiply(double n)` | result *= n |
| `getResult()` | current result |
| `save(label)` | returns a `CalculatorMemento` of the current result |
| `restore(memento)` | resets result from the memento |

**Caretaker — `UndoHistory`:** a stack of mementos with `push`, `pop`, `isEmpty`.

### What to implement

1. `CalculatorMemento`, `Calculator`, `UndoHistory` — one file per type in all 4 languages
2. `Main`:
   - Start at 0
   - Save, then `add(10)` → 10
   - Save, then `multiply(3)` → 30
   - Save, then `subtract(5)` → 25
   - Undo → 30, Undo → 10, Undo → 0

### Expected Output (shape)

```
Start: 0.0
add 10    -> 10.0
multiply 3 -> 30.0
subtract 5 -> 25.0
Undo -> 30.0
Undo -> 10.0
Undo -> 0.0
```

## Constraints

- One file per class/type
- The `Calculator`'s result field stays private; only it reads a memento's value
- `UndoHistory` treats mementos as opaque — it never reads the stored number
- Undo on an empty history must be handled gracefully (print a message, don't crash)

## Stretch Goal (optional)

Add **redo**: when you undo, push the undone snapshot onto a redo stack so `redo()` can re-apply it.

## Submission

Put your solution in `21-Memento/assignments/easy/src/{java,cpp,rust,go}/`.
