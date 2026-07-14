# Assignment: Expression Tree Calculator (Medium)

## Objective

Combine the Composite pattern with recursive evaluation to build a **mathematical expression tree**. This connects to OOP (Ch01 — polymorphism) and demonstrates a non-file-system use of Composite.

## Context

Mathematical expressions like `(3 + 5) * (2 - 1)` can be represented as trees:

```
        *
       / \
      +   -
     / \ / \
    3  5 2  1
```

**Leaves** are numbers. **Composites** are operators that combine two sub-expressions.

## Requirements

### Component — `Expression`

| Method | Description |
|--------|-------------|
| `evaluate()` | Returns the numeric result |
| `toString()` | Returns the expression as a readable string |

### Leaf — `NumberExpr`
- Stores a single `double` value
- `evaluate()` returns that value
- `toString()` returns the number as string (e.g., `"3.0"`)

### Composites — Operator Expressions

| Class | Operation | `evaluate()` | `toString()` |
|-------|-----------|-------------|-------------|
| `AddExpr` | + | left + right | `(left + right)` |
| `SubExpr` | - | left - right | `(left - right)` |
| `MulExpr` | * | left * right | `(left * right)` |
| `DivExpr` | / | left / right | `(left / right)` |

Each operator has `left` and `right` children (both are `Expression`).

### What to implement

1. **`Expression`** — component interface
2. **`NumberExpr`** — leaf
3. **`AddExpr`**, **`SubExpr`**, **`MulExpr`**, **`DivExpr`** — composites
4. **`Main`** — build and evaluate these expressions:

```
Expression 1: (3 + 5) = 8.0
Expression 2: (10 - 4) = 6.0
Expression 3: (3 + 5) * (2 - 1) = 8.0
Expression 4: ((6 / 2) + (7 * 3)) = 24.0
Expression 5: ((2 + 3) * (4 - 1)) / (10 - 5) = 3.0
```

### Expected Output

```
=== Expression Tree Calculator ===

(3.0 + 5.0) = 8.0
(10.0 - 4.0) = 6.0
((3.0 + 5.0) * (2.0 - 1.0)) = 8.0
((6.0 / 2.0) + (7.0 * 3.0)) = 24.0
(((2.0 + 3.0) * (4.0 - 1.0)) / (10.0 - 5.0)) = 3.0
```

## Constraints

- One file per class/type
- No `instanceof` in client code
- `DivExpr` should handle division by zero (throw/panic or return special value)
- `evaluate()` must work recursively — composites evaluate their children first
- `toString()` must fully parenthesize the expression

## Key Learning

This is a **binary tree** Composite (each node has exactly 2 children) vs the file system's **n-ary tree** (each directory has N children). Both are Composite — same pattern, different shapes.

## Submission

Put your solution in `12-Composite/assignments/medium/src/{java,cpp,rust,go}/`.
