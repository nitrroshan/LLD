# Chapter 40 — Assignment (Medium)

## Order batching onto one agent + geospatial assignment

The **scaling** upgrade — the real Swiggy/Zomato optimization. Replace one-order-per-agent
with **batched** deliveries, and replace the linear agent scan with a **geospatial index**.

### Part A — Order batching (a new assignment Strategy)

Currently each order gets its own agent (`NearestAgentAssignmentStrategy`, and the agent goes
unavailable). Real platforms give an agent **multiple** nearby orders heading the same way.

Requirements:
- Let a `DeliveryAgent` hold a small **list of active orders** with a capacity (e.g., max 2).
  "Available" becomes "has spare capacity."
- Add a `BatchingAssignmentStrategy` that prefers an agent who **already** has an order from
  the same (or a nearby) restaurant and still has capacity; only if none exists does it fall
  back to the nearest free agent.
- The strategy must implement the existing `DeliveryAssignmentStrategy` interface — the
  `FoodDeliveryService` dispatch flow is unchanged.
- On delivery, remove the order from the agent's list and restore capacity.

Design question to answer: batching trades **lower delivery cost** for **higher latency** for
the first customer (their food waits while the agent picks up a second order). How would you
bound that (max detour, max wait)? Where does that policy live?

### Part B — Geospatial agent index

Replace scanning **all** agents with querying only **nearby** ones.

Requirements:
- Add an `AgentIndex` that buckets agents into a **uniform grid** by location (cell size `C`;
  an agent at `(x, y)` → cell `(floor(x/C), floor(y/C))`). A quadtree is a bonus.
- Support `addAgent`, `updateAgentLocation` (re-buckets), and `nearbyAgents(location, radius)`
  returning agents in the location's cell + neighbors — **not** a full scan.
- The `BatchingAssignmentStrategy` (or a `GridAssignmentStrategy`) asks the index for nearby
  candidates, then chooses among just those.

Design question to answer: what does the grid cell size trade off, and how does a quadtree
handle **uneven agent density** (busy downtown vs quiet suburb) better than a uniform grid?

### Part C — Atomic assignment note (design only)

In a comment or `DESIGN.md`, describe how you'd prevent **two orders being dispatched to the
same last-capacity agent at once** (lock the agent / CAS remaining-capacity), tying it back to
the ride-sharing (Ch39) and parking-lot chapters.

### Constraints

- Batching and the grid index are **new classes**; the `FoodDeliveryService` dispatch method
  keeps calling `DeliveryAssignmentStrategy.selectAgent(...)`.
- The index query must inspect **nearby cells only**, not all agents.

### Demo (extend `Main` / `main.cpp`)

1. Place two orders from the same restaurant close in time; show the **batching** strategy
   assigns **both to one agent** (with capacity), not two agents.
2. Add many agents across a grid; dispatch an order and print the **candidate count** (nearby
   cells) vs the total agent count to show it's not a full scan.

### What good looks like

- An agent can carry multiple batched orders; capacity is respected.
- Assignment inspects only nearby cells (O(nearby), not O(all)) behind the same Strategy
  interface.
- A crisp note on the batching latency/cost trade-off and atomic assignment under concurrency.
