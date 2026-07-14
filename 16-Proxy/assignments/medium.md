# Assignment: Cached Database Proxy (Medium)

## Objective

Build a **caching proxy** in front of a slow database, and combine it with the **Singleton** pattern (Chapter 08) so the whole app shares one cache, plus a light **Facade**-style entry point (Chapter 14) for the query API.

## Background

A `UserDatabase` performs "slow" lookups by id. Re-fetching the same user repeatedly is wasteful. A caching proxy stores results the first time and serves subsequent identical requests from memory. To ensure the cache is shared app-wide, the proxy (or its cache) is a singleton.

## Part 1 — The Subject and Real Object

**Subject — `UserRepository`:**

| Method | Description |
|--------|-------------|
| `getUser(int id)` | returns a user's name for the given id |

**RealSubject — `RealUserDatabase`:**

- `getUser(id)` simulates a slow query: print `[DB] Querying user <id> (slow)...` then return a name like `"User#<id>"`
- Keep a counter `queryCount` of how many real queries actually happened

## Part 2 — The Caching Proxy

**`CachingUserProxy` implements `UserRepository`:**

- Holds a reference to a `RealUserDatabase` and a `Map<Integer, String>` cache
- `getUser(id)`:
  - **cache hit** → print `[Cache] Hit for user <id>` and return the cached value (no DB call)
  - **cache miss** → delegate to the real DB, store the result, print `[Cache] Stored user <id>`
- Expose `cacheSize()` and the underlying `queryCount()`

## Part 3 — Combine with Singleton (Ch08)

Make the caching proxy a **singleton** so every part of the app shares one cache:

- A single global access point (`CachingUserProxy.getInstance()` in Java, `sync.Once` in Go, `OnceCell`/`lazy_static`-style in Rust, a static local in C++)
- Two different callers requesting the **same** user id must result in **one** DB query total

## Part 4 — Facade-style API (Ch14, light touch)

Add a small `UserService` with a method `displayUser(int id)` that:
- Gets the user through the singleton caching proxy
- Prints `Showing: <name>`

The client uses `UserService` and never touches the DB or the cache directly.

### What to implement

1. `UserRepository`, `RealUserDatabase`, `CachingUserProxy` (singleton), `UserService`
2. `Main`:
   - Request user `1` twice, user `2` once, user `1` again
   - Show that only **2** real DB queries happened despite **4** requests

### Expected Result

```
[DB] Querying user 1 (slow)...
[Cache] Stored user 1
Showing: User#1
[Cache] Hit for user 1
Showing: User#1
[DB] Querying user 2 (slow)...
[Cache] Stored user 2
Showing: User#2
[Cache] Hit for user 1
Showing: User#1

Real DB queries: 2
Cache size:      2
```

## Constraints

- One file per class/type in all 4 languages
- Proxy and real DB implement the **same** `UserRepository` interface
- Caching logic lives only in the proxy; `RealUserDatabase` has no cache awareness
- The singleton must guarantee a single shared cache instance
- Be mindful of thread safety in the lazy singleton (note it even if your demo is single-threaded)

## Stretch Goal (optional)

Add `invalidate(int id)` to the proxy that evicts one entry, and show that the next `getUser(id)` triggers a fresh DB query — demonstrating cache invalidation.

## Submission

Put your solution in `16-Proxy/assignments/medium/src/{java,cpp,rust,go}/`.
