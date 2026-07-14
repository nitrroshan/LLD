# Assignment: Pizza Topping System (Easy)

## Objective

Apply the Decorator pattern to build a pizza ordering system where toppings are stacked dynamically.

## Requirements

**Component — `Pizza`:**

| Method | Description |
|--------|-------------|
| `getDescription()` | Full description with all toppings |
| `getCost()` | Total cost including all toppings |

**Base pizzas (Concrete Components):**

| Pizza | Cost | Description |
|-------|------|-------------|
| `PlainPizza` | $5.00 | "Plain Pizza" |
| `ThinCrust` | $6.00 | "Thin Crust Pizza" |

**Toppings (Decorators):**

| Topping | Added Cost |
|---------|-----------|
| `CheeseTopping` | +$1.50 |
| `PepperoniTopping` | +$2.00 |
| `MushroomTopping` | +$1.00 |
| `OliveTopping` | +$0.75 |

### What to implement

1. `Pizza` — component interface
2. `PlainPizza`, `ThinCrust` — concrete components
3. `PizzaDecorator` — abstract decorator (optional — can skip in Go/Rust)
4. All 4 topping decorators
5. `Main` — create these orders:
   - Plain + Cheese = $6.50
   - Thin Crust + Cheese + Pepperoni + Mushroom = $10.50
   - Plain + Cheese + Cheese (double cheese!) = $8.00
   - Thin Crust + everything = $11.25

### Expected Output

```
  Plain+Cheese:    Plain Pizza, Cheese — $6.50
  Loaded Thin:     Thin Crust Pizza, Cheese, Pepperoni, Mushroom — $10.50
  Double Cheese:   Plain Pizza, Cheese, Cheese — $8.00
  Everything:      Thin Crust Pizza, Cheese, Pepperoni, Mushroom, Olives — $11.25
```

## Constraints

- One file per class/type
- Same decorator can be applied multiple times (double cheese)
- No `instanceof` / type checks

## Submission

Put your solution in `13-Decorator/assignments/easy/src/{java,cpp,rust,go}/`.
