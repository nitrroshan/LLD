# Assignment: HTTP Request Builder (Medium)

## Objective

Combine the Builder pattern with concepts from earlier chapters (encapsulation, SRP) to build a realistic **HTTP Request** object.

## Context

HTTP requests have many parts — some required, some optional. This is a perfect fit for Builder. Real-world libraries like OkHttp (Java), reqwest (Rust), and net/http (Go) use builder-like patterns for constructing requests.

## Requirements

Build an **HTTP Request builder** where each request has:

| Field | Type | Default | Required? |
|-------|------|---------|-----------|
| method | String ("GET", "POST", "PUT", "DELETE") | — | **Yes** |
| url | String | — | **Yes** |
| headers | Map/Dictionary of key-value pairs | empty | No |
| queryParams | Map/Dictionary of key-value pairs | empty | No |
| body | String | null/empty | No |
| timeout | int (milliseconds) | 30000 | No |
| followRedirects | boolean | true | No |
| authToken | String | null/empty | No |

### What to implement

1. **`HttpRequest`** — Immutable product. Stores all the fields above. Has a readable `toString()` / `Display`.
2. **`HttpRequestBuilder`** — Fluent builder. `method` and `url` are required (validate in `build()`).
3. **`header(key, value)`** — Adds a single header. Can be called multiple times.
4. **`queryParam(key, value)`** — Adds a single query parameter. Can be called multiple times.
5. **`build()`** — Validates:
   - `method` is one of GET/POST/PUT/DELETE
   - `url` is not empty
   - If method is GET/DELETE, `body` should be empty (warn or reject)
6. **`HttpRequestDirector`** — Pre-built requests:
   - `buildGetRequest(url)` — Simple GET with default timeout
   - `buildAuthenticatedPost(url, token, body)` — POST with auth header and JSON content-type
   - `buildApiCall(url, apiKey)` — GET with `X-API-Key` header and no-redirect

### Expected Output

```
GET https://api.example.com/users
  Headers: {}
  Params: {}
  Timeout: 30000ms, Redirects: true

POST https://api.example.com/users
  Headers: {Content-Type: application/json, Authorization: Bearer abc123}
  Params: {}
  Body: {"name": "Alice"}
  Timeout: 30000ms, Redirects: true

GET https://api.example.com/data?page=1&limit=10
  Headers: {X-API-Key: key-xyz}
  Params: {page: 1, limit: 10}
  Timeout: 30000ms, Redirects: false
```

## Constraints

- One file per class
- `HttpRequest` must be **immutable**
- Headers and query params accumulate via repeated builder calls (not replaced)
- Validate method + url in `build()`
- The Director should demonstrate at least 3 pre-built configurations

## Design Hints

- In Java, use `Map<String, String>` for headers/params. In C++, use `std::map`. In Rust, `HashMap`. In Go, `map[string]string`.
- The builder should own its own copy of the maps to avoid shared mutation.
- Think about SRP: validation logic can live in `build()`, but complex URL parsing would be a separate concern.

## Submission

Put your solution in `07-Builder/assignments/medium/src/{java,cpp,rust,go}/`.
