# Chapter 39 — Assignment (Medium)

## Geospatial driver index + short-TTL location caching

The **scaling** upgrade — this is the follow-up a real Uber interview centers on. Replace the
linear driver scan with a **geospatial index**, and fix the caching proxy so it doesn't serve
**stale driver positions**.

### Part A — Geospatial matching (grid / quadtree)

The current `NearestDriverMatchingStrategy` scans **all** available drivers — O(drivers). At
city scale that's far too slow. Add a spatial index so matching only looks at drivers **near**
the pickup.

Requirements:
- Add a `DriverIndex` that buckets drivers by location into a **uniform grid** (e.g., cells of
  size `C`; a driver at `(x, y)` lands in cell `(floor(x/C), floor(y/C))`). A **quadtree** is a
  bonus.
- Support:
  - `addDriver` / `updateDriverLocation` (moving a driver re-buckets it),
  - `nearbyDrivers(pickup, radius)` returning only drivers in the pickup's cell and its
    neighbors — **not** a full scan.
- Add a `GridMatchingStrategy` that asks the index for nearby candidates, then picks the best
  among just those. It must implement the same `RideMatchingStrategy` interface, so the
  service is unchanged.

Design question to answer: what does the grid cell size trade off? (Too big → still scanning
many; too small → must check more neighbor cells.) How would a quadtree adapt to uneven driver
density better than a uniform grid?

### Part B — Short-TTL location caching (fix the stale-cache bug)

The current `CachingLocationServiceProxy` caches **forever**. That's fine for a fixed
pickup→drop distance, but **wrong** for live driver positions, which move.

Requirements:
- Give the proxy a **time-to-live (TTL)**: each cache entry stores the value **and** a
  timestamp; on lookup, entries older than `ttl` are treated as misses and recomputed. Use an
  injectable/mockable clock (an integer "tick" is fine for a deterministic demo).
- Demonstrate: a lookup, a **cache hit** within the TTL, then advance the clock past the TTL and
  show the **same** lookup recomputes (a miss) — because the position may have changed.

Design write-up (comments or `DESIGN.md`): articulate **what is safe to cache vs not** — an
immutable pickup→drop distance (cache freely) vs a live driver's location (short TTL or don't
cache). This is the "caching invalidation" insight the interviewer is fishing for.

### Part C — Atomic assignment note (design only)

In a comment, describe how you'd stop **two riders being matched to the same driver at once**
(lock the driver / CAS `available` true→false / a distributed lock), tying it back to the
parking-lot and BookMyShow chapters. No threading code required.

### Constraints

- The grid/quadtree index is a **new class**; `GridMatchingStrategy` reuses the existing
  `RideMatchingStrategy` interface — the service is unchanged.
- TTL logic lives **inside the proxy**; callers still just call `getDistance` and are unaware.

### Demo (extend `Main` / `main.cpp`)

1. Add many drivers across a grid; request a ride and show matching only inspects **nearby**
   cells (print the candidate count vs total drivers).
2. Show a TTL cache hit, then a recompute after the clock advances past the TTL.

### What good looks like

- Matching is O(nearby), not O(all), behind the same Strategy interface.
- The proxy caches with a TTL; a clear written distinction of what's safe to cache.
- A crisp note on atomic driver assignment under concurrency.
