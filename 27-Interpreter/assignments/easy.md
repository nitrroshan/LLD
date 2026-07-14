# Assignment: Arithmetic Expression Interpreter (Easy)

## Objective

Apply the Interpreter pattern to evaluate simple **arithmetic** expressions built from numbers and `+`, `-`, `*` operators, against no context (or a variable context).

## Background

Where the chapter example returned `boolean`, this one returns a **number**. The structure is identical: terminals (numbers, variables) and non-terminals (add, subtract, multiply). You build the tree by hand and interpret it.

## Requirements

**AbstractExpression — `Expression`:** `interpret(Context context) → double`

**Context — `Context`:** maps variable names to numeric values (`get(name)`, `set(name, value)`).

**Terminal expressions (one file each):**

| Class | interpret returns |
|-------|-------------------|
| `Number` | its literal value |
| `Variable` | `context.get(name)` |

**Non-terminal expressions (one file each):**

| Class | interpret returns |
|-------|-------------------|
| `Add` | `left + right` |
| `Subtract` | `left - right` |
| `Multiply` | `left * right` |

### What to implement

1. `Expression`, `Context`, `Number`, `Variable`, `Add`, `Subtract`, `Multiply` — one file per type in all 4 languages
2. `Main`:
   - Build `(x + 5) * (10 - 3)` where `x = 2` → `(2 + 5) * 7 = 49`
   - Evaluate with `x = 2`, then again with `x = 0` → `35`

### Expected Output (shape)

```
Expression: (x + 5) * (10 - 3)
  x=2 -> 49
  x=0 -> 35
```

## Constraints

- One file per class/type
- Each rule is its own class with an `interpret` method — no central evaluator with a big switch
- Adding a new operator (e.g., `Divide`) must require **no** change to existing expression classes
- The context supplies variable values; terminals/non-terminals never hard-code them

## Submission

Put your solution in `27-Interpreter/assignments/easy/src/{java,cpp,rust,go}/`.
