# Assignment: Pizza Builder (Easy)

## Objective

Apply the Builder pattern to construct a `Pizza` object with many optional toppings.

## Requirements

Build a **pizza ordering system** where each pizza has:

| Field | Type | Default | Required? |
|-------|------|---------|-----------|
| size | String ("small", "medium", "large") | — | **Yes** |
| crustType | String ("thin", "regular", "stuffed") | "regular" | No |
| sauce | String ("tomato", "bbq", "white") | "tomato" | No |
| cheese | boolean | true | No |
| pepperoni | boolean | false | No |
| mushrooms | boolean | false | No |
| onions | boolean | false | No |
| olives | boolean | false | No |
| extraCheese | boolean | false | No |

### What to implement

1. **`Pizza`** — Immutable product class. No setters. All fields set at construction.
2. **`PizzaBuilder`** — Fluent builder with method chaining. `size` is required (pass it to the builder constructor or validate in `build()`).
3. **`build()`** — Must validate that `size` is provided and is one of the valid values.
4. **`Main`** — Create at least 3 pizzas:
   - A simple cheese pizza (small, defaults)
   - A loaded pizza (large, stuffed crust, all toppings)
   - A custom pizza (your choice)

### Expected Output

```
Pizza [large, stuffed crust, bbq sauce, cheese, pepperoni, mushrooms, onions, olives, extra cheese]
Pizza [small, regular crust, tomato sauce, cheese]
Pizza [medium, thin crust, white sauce, cheese, mushrooms, olives]
```

## Constraints

- One file per class (all 4 languages)
- Pizza must be **immutable** — no setters on Pizza itself
- Builder must return `this`/`self` for chaining
- Validate `size` in `build()` — throw/panic if missing or invalid

## Bonus

Add a `PizzaDirector` with pre-built recipes: `orderMargherita()`, `orderMeatLovers()`, `orderVeggie()`.

## Submission

Put your solution in `07-Builder/assignments/easy/src/{java,cpp,rust,go}/`.
