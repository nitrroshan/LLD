# Assignment: Smart Scheduling + Priority Requests (Design + Code)

## Objective

Add a **wait-minimizing scheduling strategy** and **priority requests** (e.g., VIP or emergency), deepening Strategy and Command, and using a **priority queue** in the controller. Implement in **Java and C++**.

## Part 1 — Smarter Scheduling (Strategy)

Add a `MinimalWaitStrategy` that estimates, for each elevator, how long the requester would wait, and picks the minimum. A simple cost model:

- If the elevator is **idle**: cost = distance to the request floor.
- If it's **moving toward** the request floor in a compatible direction: cost = distance.
- If it's moving **away** or in the wrong direction: cost = distance + a penalty proportional to its remaining stops.

Choose the elevator with the lowest estimated cost. This must slot in **without changing** `Elevator` or the other strategies.

## Part 2 — Priority Requests (Command)

Add a `PriorityRequest` (implements `Request`) carrying a priority level (e.g. `EMERGENCY`, `VIP`, `NORMAL`). The controller processes queued requests **highest-priority first**.

- The controller holds a **priority queue** of pending requests instead of dispatching immediately.
- Each tick (or before running), it drains the queue in priority order and dispatches via the strategy.
- An `EMERGENCY` request (e.g., firefighter recall) should be served before any normal calls.

## Part 3 — Wire it together

- The controller now: `enqueue(request)` → `dispatchPending()` (priority order) → `run(ticks)`.
- Show that submitting a NORMAL call and then an EMERGENCY call results in the emergency being dispatched first.

## Design Tasks (answer in `DESIGN.md`)

1. `MinimalWaitStrategy` needs each elevator's direction and pending load. Is exposing `direction()`/`targetCount()` enough, or do you need a richer read-only view? Keep the strategy decoupled from `Elevator`'s internals.
2. Why model priority on the **Request** (Command) rather than as a flag the controller tracks separately?
3. Where does the **priority queue** belong — controller or elevator? Justify with Single Responsibility.

## Implementation Requirements

- `MinimalWaitStrategy implements SchedulingStrategy`.
- `PriorityRequest implements Request` with a comparable priority.
- Controller uses a priority queue; `enqueue` + `dispatchPending`.
- Demo: mixed normal + priority calls across two elevators; show ordering and pluggable strategy.

## Constraints

- One file per class/type in **Java and C++**
- Adding the new strategy or request type must not modify `Elevator` or existing strategies/requests (OCP)
- The strategy stays decoupled from `Elevator`'s private state
- Emergencies preempt normal calls in dispatch order

## Stretch Goal (optional)

Add **capacity**: each elevator tracks passenger count; car requests beyond capacity are refused, and the requester is re-dispatched to another car.

## Submission

Put your solution in `29-Elevator/assignments/medium/src/{java,cpp}/` with a short `DESIGN.md`.
