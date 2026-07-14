# Assignment: Shipping Cost Calculator (Medium)

## Objective

Build a checkout system that computes **shipping cost** using interchangeable strategies, and combine Strategy with the **Factory Method** (Ch05) to pick the strategy from a shipping-option name — plus show strategies that carry their own configuration.

## Background

An online store offers several shipping options, each with a different cost algorithm: flat rate, weight-based, or free-over-threshold. The order (context) shouldn't hard-code these; it delegates to a `ShippingStrategy`. A factory maps the user's chosen option string to the right strategy so the client stays decoupled.

## Part 1 — The Strategy and its variants

**`Order`:** has a `weight` (kg) and a `subtotal` ($).

**Strategy — `ShippingStrategy`:** `double calculate(Order order)`

**Concrete strategies (one file each):**

| Strategy | Cost rule |
|----------|-----------|
| `FlatRateShipping` | always `$5.00` |
| `WeightBasedShipping` | `$1.50 × weight` (rounded to cents) |
| `FreeOverThresholdShipping` | free if `subtotal >= threshold` (configurable, e.g. $50), else falls back to `$7.00` |

Note `FreeOverThresholdShipping` carries **its own configuration** (the threshold) — strategies can hold state/params.

## Part 2 — Factory Method (Ch05)

**`ShippingFactory`** with `create(String option)`:

| option | strategy |
|--------|----------|
| `"flat"` | `FlatRateShipping` |
| `"weight"` | `WeightBasedShipping` |
| `"free-over-50"` | `FreeOverThresholdShipping(50)` |

The client asks the factory for a strategy by name — it never news up a concrete strategy directly.

## Part 3 — The Context

**`Checkout`:**

| Method | Behavior |
|--------|----------|
| `setShippingStrategy(ShippingStrategy)` | choose the strategy |
| `total(Order)` | returns `subtotal + strategy.calculate(order)` |

### What to implement

1. `Order`, `ShippingStrategy`, the 3 concrete strategies, `ShippingFactory`, `Checkout`
2. `Main`:
   - Order A: weight 2 kg, subtotal $30 — compute total under all three strategies (obtained via the factory)
   - Order B: weight 1 kg, subtotal $80 — show `free-over-50` makes shipping free

### Expected Result (shape)

```
Order A (2kg, $30):
  flat        -> shipping $5.00,  total $35.00
  weight      -> shipping $3.00,  total $33.00
  free-over-50 -> shipping $7.00, total $37.00
Order B (1kg, $80):
  free-over-50 -> shipping $0.00, total $80.00
```

## Constraints

- One file per class/type in all 4 languages
- `Checkout` delegates cost to the strategy — no shipping formulas inside it
- The factory hides which concrete strategy is chosen
- Adding a new shipping option must not modify `Checkout` or existing strategies
- `FreeOverThresholdShipping` must store its threshold as configuration, not hard-code 50 in the class body

## Design Question to Answer (in a comment)

This resembles the **State** pattern structurally. Explain in 2–3 sentences why it's **Strategy**: who chooses the algorithm, and do the algorithms transition into one another? (They don't — the client picks one; that's Strategy.)

## Submission

Put your solution in `22-Strategy/assignments/medium/src/{java,cpp,rust,go}/`.
