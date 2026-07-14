# Assignment: Bullet System in a Game (Easy)

## Objective

Apply the Flyweight pattern to a shooter game that fires thousands of bullets, keeping memory low by sharing each bullet **type**.

## Background

A bullet has data that is **identical** for every bullet of the same kind (sprite image, damage, speed) and data that is **unique** per bullet (its current x/y position and direction). Sharing the identical part is the whole point of Flyweight.

## Requirements

**Flyweight — `BulletType` (intrinsic state):**

| Field | Example |
|-------|---------|
| `name` | `"Pistol"`, `"Rocket"`, `"Laser"` |
| `sprite` | `"pistol.png"` |
| `damage` | `10` |
| `speed` | `50` |

Method: `render(int x, int y)` → prints `Rendering Rocket [dmg=50, spd=20] at (x, y)`

**Flyweight Factory — `BulletTypeFactory`:**

| Method | Behavior |
|--------|----------|
| `getBulletType(name, sprite, damage, speed)` | Return a cached `BulletType` if one with this `name` exists; otherwise create, cache, and return it. Print `[Factory] Created bullet type: <name>` only on creation. |
| `distinctTypeCount()` | How many distinct types were created |

**Context — `Bullet` (extrinsic state):**

| Field | Meaning |
|-------|---------|
| `x`, `y` | Current position (unique per bullet) |
| `type` | Reference to a shared `BulletType` |

Method: `move()` → advances the bullet (e.g. `y += type.speed`) then calls `type.render(x, y)`.

**Client — `Game`:**

| Method | Behavior |
|--------|----------|
| `fire(x, y, name, sprite, damage, speed)` | Get the flyweight from the factory, create a `Bullet`, store it |
| `updateAll()` | Call `move()` on every bullet |

### What to implement

1. `BulletType`, `BulletTypeFactory`, `Bullet`, `Game` — one file per type in all 4 languages
2. `Main` — fire **10,000 bullets** across just **3 types** (Pistol, Rocket, Laser), then print the distinct-type count (must be `3`)

### Expected Output (shape)

```
[Factory] Created bullet type: Pistol
[Factory] Created bullet type: Rocket
[Factory] Created bullet type: Laser
Bullets fired:      10000
Distinct types:     3
```

## Constraints

- One file per class/type
- `BulletType` must be **immutable** — no setters, `final`/`const`/`Rc` as appropriate
- Position (`x`, `y`) must **never** be stored inside `BulletType`
- All bullet-type creation must go **through the factory** — no direct `new BulletType(...)` in `Game`

## Submission

Put your solution in `15-Flyweight/assignments/easy/src/{java,cpp,rust,go}/`.
