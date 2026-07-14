# Assignment: Mini Rule Engine (Medium)

## Objective

Build a small **rule engine** that evaluates business rules over a data record, using the Interpreter pattern — and combine it with **Builder** (Ch07) for a fluent rule-construction API and a light **Factory** (Ch05) touch to parse simple rule tokens.

## Background

Business rules like "customer is premium AND (age >= 18 OR has guardian consent)" are naturally expressed as an expression tree. Each condition is an interpreter node evaluated against a `Facts` context. A fluent builder makes assembling rules readable, and a small factory can turn comparison tokens into leaf expressions.

## Part 1 — Context and comparison terminals

**Context — `Facts`:** a map of `field -> value` where values can be numbers, strings, or booleans (use your language's idiomatic approach — a tagged value/`any`/enum).

**Terminal expressions (comparisons):**

| Expression | interpret(facts) |
|------------|------------------|
| `Equals(field, value)` | `facts[field] == value` |
| `GreaterThan(field, number)` | `facts[field] > number` |
| `IsTrue(field)` | `facts[field] == true` |

## Part 2 — Boolean non-terminals

`And`, `Or`, `Not` — same as the chapter example, combining sub-rules.

## Part 3 — Combine with Builder (Ch07)

Provide a `RuleBuilder` with a fluent API to assemble a rule, e.g.:

```
Rule rule = RuleBuilder.create()
    .equals("tier", "premium")
    .and()
    .group(g -> g.greaterThan("age", 18).or().isTrue("hasConsent"))
    .build();
```

(Adapt the exact fluent shape to each language; the point is a readable builder that produces an `Expression` tree.)

## Part 4 — Light Factory (Ch05, optional but encouraged)

A `ComparisonFactory.create(field, op, value)` that returns the right terminal (`"=="` → Equals, `">"` → GreaterThan, `"isTrue"` → IsTrue), so rules can be built from parsed tokens without the client knowing concrete classes.

### What to implement

1. `Expression`, `Facts`, the 3 comparison terminals, `And`/`Or`/`Not`
2. `RuleBuilder` (fluent), and optionally `ComparisonFactory`
3. `Main`:
   - Build the rule: `tier == "premium" AND (age > 18 OR hasConsent == true)`
   - Evaluate against three fact sets:
     - premium, age 25, no consent → **true**
     - premium, age 16, hasConsent true → **true**
     - basic, age 40, no consent → **false**

### Expected Result (shape)

```
Rule: tier == premium AND (age > 18 OR hasConsent)
  {tier=premium, age=25, hasConsent=false} -> true
  {tier=premium, age=16, hasConsent=true}  -> true
  {tier=basic,   age=40, hasConsent=false} -> false
```

## Constraints

- One file per class/type in all 4 languages
- Each rule/comparison is its own interpreter node — no monolithic evaluator
- Adding a new comparison or boolean operator must not modify existing nodes
- The builder produces a plain `Expression` tree — evaluation stays in the interpreter nodes
- Keep parsing (if any) separate from interpreting

## Design Questions to Answer (in a comment)

1. Which pattern gives the **evaluation** (Interpreter) and which gives the **construction** (Builder)? Why is separating them useful?
2. The chapter says Interpreter suits only *simple, stable* grammars. At what point would you abandon this hand-rolled approach for a real parser, and why?

## Stretch Goal (optional)

Add a `toString()` on each node so the whole rule can print itself (this is essentially a second operation over the tree — note how a **Visitor** (Ch26) would let you add printing, validation, etc. without touching the nodes).

## Submission

Put your solution in `27-Interpreter/assignments/medium/src/{java,cpp,rust,go}/`.
