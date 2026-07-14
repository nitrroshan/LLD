# Assignment: Event Bus with Typed Events (Medium)

## Objective

Build a small **event bus** where publishers emit typed events and subscribers react only to the event **types** they care about — a step toward publish/subscribe — and combine Observer with a light **Singleton** (Ch08) for a shared bus.

## Background

A weather station push to displays is one subject to many observers. A real app has *many* event kinds (user signed up, order placed, temperature changed) and subscribers that only want *some* of them. An event bus routes each event to the handlers registered for that event type. This generalizes Observer toward Pub/Sub.

## Part 1 — Events

Define an `Event` base/interface with a `name()` (the event type) and concrete events carrying data:

| Event | Data |
|-------|------|
| `UserSignedUp` | `username` |
| `OrderPlaced` | `orderId`, `amount` |
| `TemperatureChanged` | `celsius` |

## Part 2 — The Event Bus (Subject)

**`EventBus`:**

| Method | Behavior |
|--------|----------|
| `subscribe(String eventType, Handler handler)` | register a handler for one event type |
| `unsubscribe(String eventType, Handler handler)` | remove a handler |
| `publish(Event event)` | deliver the event to **only** the handlers registered for its type |

A `Handler` is an observer: `handle(Event event)` (or a function/closure `Event -> void`).

Internally the bus keeps a map: `eventType -> list of handlers`.

## Part 3 — Shared bus via Singleton (Ch08)

Make the `EventBus` a **singleton** so the whole app shares one bus (a single global access point; be mindful of thread-safety as noted in Ch08). Publishers and subscribers all use `EventBus.getInstance()`.

### What to implement

1. `Event` + the 3 concrete events
2. `Handler` (interface or function type) + `EventBus` (singleton)
3. `Main`:
   - Subscribe a handler to `"UserSignedUp"` that prints a welcome
   - Subscribe two handlers to `"OrderPlaced"` (one logs, one bills)
   - Subscribe a handler to `"TemperatureChanged"`
   - Publish one of each event and show only the matching handlers fire
   - Unsubscribe the billing handler and publish another `OrderPlaced` — only the logger reacts

### Expected Result (shape)

```
publish UserSignedUp(alice)
  Welcome, alice!
publish OrderPlaced(#1001, $250)
  [Log] order #1001 recorded
  [Billing] charging $250 for #1001
publish TemperatureChanged(30)
  [Weather] now 30°C
-- billing handler unsubscribed --
publish OrderPlaced(#1002, $80)
  [Log] order #1002 recorded
```

## Constraints

- One file per class/type in all 4 languages
- A handler only receives events of the **type it subscribed to**
- The bus depends only on the `Handler`/`Event` abstractions, never concrete publishers
- The singleton must ensure a single shared bus instance
- Iterating handlers must tolerate an unsubscribe happening between publishes

## Design Question to Answer (in a comment)

How is this event bus **closer to Pub/Sub than plain Observer**? (Hint: publishers and subscribers don't reference each other at all — the bus/broker sits between them and routes by event type.)

## Stretch Goal (optional)

Add a wildcard subscription (`subscribe("*", handler)`) that receives **every** event, useful for logging/metrics.

## Submission

Put your solution in `23-Observer/assignments/medium/src/{java,cpp,rust,go}/`.
