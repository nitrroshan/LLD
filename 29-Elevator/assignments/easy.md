# Assignment: Formalize Elevator State (Design + Code)

## Objective

The chapter models the elevator's status as an **enum** (`IDLE` / `MOVING` / `DOORS_OPEN`) with transition logic inside `step()`. Refactor it into the **State pattern** (Ch25) so each state is its own class — a direct bridge between a case study and a core pattern.

## Background

Right now `Elevator.step()` branches on `status` and `direction`. As you add behaviors (maintenance mode, overload hold, express mode), that method grows into a tangle of conditionals — exactly what State solves. Move the per-state behavior into state objects.

## Design Tasks (answer in `DESIGN.md`)

1. Define an `ElevatorState` interface with the actions that vary by state — e.g. `step(elevator)`, `onArrive(elevator)`. Which methods truly differ per state?
2. Identify the states and their transitions:
   - `IdleState` → when a target is added, move toward it.
   - `MovingState` → advance one floor; on reaching a target, go to `DoorsOpenState`.
   - `DoorsOpenState` → after serving, return to `MovingState` or `IdleState`.
3. Where do transitions live — in the states (GoF classic) or the elevator? Justify.

## Implementation Requirements

- Add `ElevatorState` + `IdleState`, `MovingState`, `DoorsOpenState`.
- `Elevator` delegates `step()` to its current state and exposes `setState(...)`, plus the data states need (`currentFloor`, `targets`, `door`).
- Preserve the LOOK movement behavior and the observer notifications.
- The demo output should match the chapter's behavior — same movement, now driven by State objects.

## Constraints

- One file per class/type in **Java and C++**
- No `switch`/`if` chain on a status field — each state object owns its behavior
- Keep `Direction` as data; it's not a separate state machine here
- Observers must still be notified on floor/status changes

## Design Question to Answer

The `ElevatorStatus` enum and the `State` pattern both represent "what state the elevator is in." When is the **enum** good enough, and when does the **State pattern** pay for its extra classes? (Hint: number of states × number of state-dependent behaviors.)

## Submission

Put your solution in `29-Elevator/assignments/easy/src/{java,cpp}/` with a short `DESIGN.md`.
