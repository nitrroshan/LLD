# Assignment: Document Access Proxy (Easy)

## Objective

Apply the Proxy pattern as a **protection proxy** — a stand-in that enforces access control before letting a caller touch a sensitive document.

## Background

A `Document` can be read by anyone but only **admins** may write to it. Instead of scattering permission checks throughout the app (or bloating the real document with auth logic), you put a proxy in front that checks the caller's role and then delegates.

## Requirements

**Subject — `Document`:**

| Method | Description |
|--------|-------------|
| `read()` | returns/prints the document content |
| `write(String content)` | replaces the content |

**RealSubject — `RealDocument`:**

- Stores content in memory (start with `"(empty)"`)
- `read()` prints `Reading: <content>`
- `write(content)` sets content and prints `Wrote: <content>`

**Protection Proxy — `DocumentProxy`:**

- Constructed with a `RealDocument` **and** a `role` string (`"ADMIN"` or `"GUEST"`)
- `read()` — always allowed; delegates to the real document
- `write(content)` — allowed **only** if `role == "ADMIN"`; otherwise print `Access denied: GUEST cannot write` and do **not** delegate

### What to implement

1. `Document` (interface/trait), `RealDocument`, `DocumentProxy` — one file per type in all 4 languages
2. `Main`:
   - Create a `RealDocument`
   - Wrap it in an **admin** proxy → `write("Q3 report")` succeeds, `read()` shows it
   - Wrap it in a **guest** proxy → `write("hack")` is denied, `read()` still works

### Expected Output (shape)

```
--- Admin ---
Wrote: Q3 report
Reading: Q3 report
--- Guest ---
Access denied: GUEST cannot write
Reading: Q3 report
```

## Constraints

- One file per class/type
- The proxy and the real document must implement the **same** `Document` interface
- Permission logic lives **only** in the proxy — `RealDocument` knows nothing about roles
- The client codes against the `Document` interface, not the concrete proxy

## Submission

Put your solution in `16-Proxy/assignments/easy/src/{java,cpp,rust,go}/`.
