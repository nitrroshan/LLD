# Assignment: Stock Ticker (Easy)

## Objective

Apply the Observer pattern to a stock ticker where multiple displays react automatically whenever a stock's price changes.

## Background

A stock (subject) has a price that changes over time. Various displays (observers) — a price board, a mobile alert, a chart — all need the latest price the instant it moves. The stock shouldn't know which displays exist; it just notifies its subscribers.

## Requirements

**Observer — `PriceObserver`:** `update(String symbol, double price)`

**Subject — `Stock`:**

| Method | Behavior |
|--------|----------|
| `subscribe(PriceObserver)` | add an observer |
| `unsubscribe(PriceObserver)` | remove an observer |
| `setPrice(double price)` | update the price and notify all subscribers |

The `Stock` has a `symbol` (e.g., `"ACME"`) and a `price`.

**Concrete observers (one file each):**

| Observer | On update prints |
|----------|------------------|
| `PriceBoard` | `[Board] <symbol>: $<price>` |
| `MobileAlert` | only prints if price crosses its `alertThreshold`: `[Alert] <symbol> hit $<price>!` |

`MobileAlert` carries its own threshold (state) and only reacts when `price >= threshold`.

### What to implement

1. `PriceObserver`, `Stock`, `PriceBoard`, `MobileAlert` — one file per type in all 4 languages
2. `Main`:
   - Create stock `"ACME"`
   - Subscribe a `PriceBoard` and a `MobileAlert(threshold = 100)`
   - Set prices: 95 → 102 → 98
   - The board reacts every time; the alert fires only at 102

### Expected Output (shape)

```
ACME -> $95.00
  [Board] ACME: $95.00
ACME -> $102.00
  [Board] ACME: $102.00
  [Alert] ACME hit $102.00!
ACME -> $98.00
  [Board] ACME: $98.00
```

## Constraints

- One file per class/type
- `Stock` depends only on the `PriceObserver` interface
- Observers can subscribe/unsubscribe at runtime
- Adding a new display must not modify `Stock`
- If your language supports it, show a **lambda/closure/function** observer as a bonus

## Submission

Put your solution in `23-Observer/assignments/easy/src/{java,cpp,rust,go}/`.
