# Assignment: Special Cells + Extra-Turn Rule (Design + Code)

## Objective

Extend the game with **special board cells** and a common house rule — **roll the max value → take another turn** — reinforcing the Factory (board elements) and the turn loop. Implement in **Java and C++**.

## New Requirements

1. **Special cells** (beyond snakes/ladders):
   - `TeleportCell` — moves the player to a fixed cell (either direction), created via the factory with validation.
   - `MineCell` — sends the player back to the start (cell 0) and emits a distinct event.
   Both are still `Jump`-like relocations, so they fit the existing board map — decide how to model them without special-casing the `Game`.
2. **Extra turn on max roll** — if a player rolls the die's maximum value (e.g., 6), they move and then **roll again** (guard against infinite loops with a cap on consecutive extra turns).

## Design Tasks (answer in `DESIGN.md`)

1. Are `TeleportCell` and `MineCell` new `Jump` subtypes, or a broader `BoardElement` abstraction? What's the cleanest way to keep `Game.playTurn` free of `if (cell is a Mine)` checks? (Hint: polymorphism — a `resolve(position)` that returns the destination.)
2. The extra-turn rule changes the turn loop. Where does it belong so it doesn't tangle with jump resolution? Could it be data (a flag on `Dice`/rules) rather than code in `Game`?
3. `MineCell` needs its **own event** so observers can react. How do you extend `GameEventListener` without breaking existing observers? (Consider a default method / adapter.)

## Implementation Requirements

- `TeleportCell` and `MineCell` (factory-created and validated).
- The extra-turn-on-max-roll rule, with a cap on consecutive bonus turns.
- A new event for hitting a mine; observers updated (existing ones must still compile).
- Demo: a board mixing snakes, ladders, a teleporter, and a mine, with the extra-turn rule active.

## Constraints

- One file per class/type in **Java and C++**
- `Game.playTurn` must resolve any cell polymorphically — no `instanceof`/type switches on cell kinds
- Adding a new cell type must not modify existing cell types (OCP)
- The extra-turn rule must not risk an infinite loop

## Submission

Put your solution in `32-Snake-And-Ladder/assignments/easy/src/{java,cpp}/` with a short `DESIGN.md`.
