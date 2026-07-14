# Assignment: Authentication Middleware Chain (Easy)

## Objective

Apply the Chain of Responsibility pattern to build a request-processing pipeline where each middleware either **passes** the request onward or **rejects** it — exactly how web frameworks handle incoming HTTP requests.

## Background

Before a web request reaches your business logic, it flows through a series of checks: is the user authenticated? do they have permission? is the request within rate limits? Each check is a link in a chain. If any link fails, the chain stops; if all pass, the request is handled.

This is the **"pure" chain** variant, but with a twist: instead of one handler processing and stopping, **every** middleware must pass the request for it to succeed.

## Requirements

**Request — `Request`:**

| Field | Meaning |
|-------|---------|
| `user` | username, or empty/null if not logged in |
| `role` | `"ADMIN"`, `"USER"`, or empty |
| `requestsThisMinute` | how many requests this user has made recently |

**Handler — `Middleware`:**

- Holds a `next` reference
- `setNext(Middleware next)` — returns `next` for fluent chaining
- `check(Request request)` — returns `boolean` (true = allowed through the whole chain)
- Base logic: if this middleware's own check passes, delegate to `next` (or return `true` if it's the last); if it fails, print the reason and return `false`

**Concrete middlewares (one file each):**

| Middleware | Passes when | On failure prints |
|------------|-------------|-------------------|
| `AuthenticationMiddleware` | `user` is present (non-empty) | `Rejected: not authenticated` |
| `AuthorizationMiddleware` | `role == "ADMIN"` | `Rejected: insufficient permissions` |
| `RateLimitMiddleware` | `requestsThisMinute < 100` | `Rejected: rate limit exceeded` |

### What to implement

1. `Request`, `Middleware` (abstract/interface), and the 3 concrete middlewares — one file per type in all 4 languages
2. `Main` — build the chain `Authentication -> Authorization -> RateLimit` and run these requests:
   - Valid admin, 5 requests → **passes** (prints `Access granted`)
   - No user → rejected at authentication
   - Logged-in `USER` role → rejected at authorization
   - Admin with 150 requests → rejected at rate limit

### Expected Output (shape)

```
Request 1 (admin, 5 reqs):
  Access granted
Request 2 (no user):
  Rejected: not authenticated
Request 3 (user role):
  Rejected: insufficient permissions
Request 4 (admin, 150 reqs):
  Rejected: rate limit exceeded
```

## Constraints

- One file per class/type
- Each middleware knows only its own check and its `next` — never the others
- Adding a new middleware must not require changing existing ones (OCP)
- The order of the chain must be configurable in `Main`, not hard-coded inside the middlewares

## Submission

Put your solution in `17-Chain-of-Responsibility/assignments/easy/src/{java,cpp,rust,go}/`.
