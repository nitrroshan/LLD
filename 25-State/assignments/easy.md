# Assignment: Traffic Light (Easy)

## Objective

Model a traffic light with the State pattern, where each light color is a state that knows how to transition to the next.

## Background

A traffic light cycles Red → Green → Yellow → Red, each color lasting for its own behavior and moving to a fixed next color. The controller doesn't contain a big `switch` on the color — each state object knows what it shows and which state comes next.

## Requirements

**State — `LightState`:**

| Method | Behavior |
|--------|----------|
| `next(TrafficLight light)` | transition the light to the next color |
| `report()` | print the current color and the action (e.g. `RED — STOP`) |

**Context — `TrafficLight`:**

| Method | Behavior |
|--------|----------|
| `change()` | delegate to the current state's `next(...)` |
| `report()` | delegate to the current state's `report()` |
| `setState(LightState)` | transition helper |

**Concrete states (one file each):**

| State | report() shows | next transitions to |
|-------|----------------|---------------------|
| `RedLight` | `RED — STOP` | `GreenLight` |
| `GreenLight` | `GREEN — GO` | `YellowLight` |
| `YellowLight` | `YELLOW — SLOW DOWN` | `RedLight` |

### What to implement

1. `LightState`, `TrafficLight`, `RedLight`, `GreenLight`, `YellowLight` — one file per type in all 4 languages
2. `Main`: start at Red, then `change()` six times, calling `report()` after each — the light should cycle twice around Red → Green → Yellow

### Expected Output (shape)

```
RED — STOP
GREEN — GO
YELLOW — SLOW DOWN
RED — STOP
GREEN — GO
YELLOW — SLOW DOWN
RED — STOP
```

## Constraints

- One file per class/type
- No `switch`/`if` chain on a color field — each state object owns its behavior and transition
- `TrafficLight` only delegates; it never decides the next color itself
- Use each language's idiom (Rust may use the consume-and-return-next-state form from the chapter example)

## Submission

Put your solution in `25-State/assignments/easy/src/{java,cpp,rust,go}/`.
