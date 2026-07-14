# Assignment: Order Processing Facade (Easy)

## Objective

Apply the Facade pattern to hide the complexity of placing an online order behind a single, simple method.

## Background

Placing an order touches **four** subsystems. Today the client has to call each one in the right order — you'll wrap that ritual in a facade.

## Requirements

**Subsystem classes (already "complex" — implement them simply, one file each):**

| Class | Method | Prints |
|-------|--------|--------|
| `Inventory` | `isAvailable(item)` | returns `true`; prints `Checking stock for <item>` |
| `Payment` | `charge(amount)` | prints `Charging $<amount>` |
| `Shipping` | `ship(item)` | prints `Shipping <item>` |
| `Notification` | `sendConfirmation(item)` | prints `Confirmation email sent for <item>` |

**Facade — `OrderFacade`:**

| Method | Behavior |
|--------|----------|
| `placeOrder(item, amount)` | 1) check inventory — if not available, print `Out of stock` and stop; 2) charge payment; 3) ship item; 4) send confirmation |

### What to implement

1. `Inventory`, `Payment`, `Shipping`, `Notification` — subsystem classes (one file each)
2. `OrderFacade` — holds all four, exposes `placeOrder(...)`
3. `Main` — place an order for `"Wireless Mouse"` costing `$25.00`

### Expected Output

```
=== Placing Order ===
Checking stock for Wireless Mouse
Charging $25.00
Shipping Wireless Mouse
Confirmation email sent for Wireless Mouse
```

## Constraints

- One file per class/type in all 4 languages
- The client (`Main`) must **only** talk to `OrderFacade` — never call a subsystem directly
- The facade only **coordinates**; no business logic (no price math) inside subsystems beyond what's listed

## Submission

Put your solution in `14-Facade/assignments/easy/src/{java,cpp,rust,go}/`.
