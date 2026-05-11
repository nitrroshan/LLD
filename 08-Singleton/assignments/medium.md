# Assignment: Thread-Safe Registry (Medium)

## Objective

Combine the Singleton pattern with a **Registry** (in-memory key-value store) that must handle concurrent access safely. This builds on Chapter 03 (SOLID — SRP) and Chapter 07 (Builder — for service configuration).

## Context

In a microservices system, a **Service Registry** keeps track of which services are available and where they're running. Think of it like a phone book: services register themselves on startup, and other services look them up by name. There should be exactly **one** registry in the application.

## Requirements

### Entities

**`ServiceInfo`** — represents a registered service:

| Field | Type | Description |
|-------|------|-------------|
| name | String | Service name (e.g., "user-service") |
| host | String | Hostname or IP |
| port | int | Port number |
| status | enum (UP, DOWN, STARTING) | Current health |
| registeredAt | long/timestamp | When it was registered |

**`ServiceRegistry`** — Singleton registry:

| Method | Description |
|--------|-------------|
| `getInstance()` | Returns the single registry |
| `register(ServiceInfo)` | Adds/updates a service entry |
| `deregister(name)` | Removes a service by name |
| `lookup(name)` | Returns ServiceInfo or null/None |
| `getAllServices()` | Returns list of all registered services |
| `getServicesByStatus(status)` | Filter by health status |
| `getServiceCount()` | Returns total registered services |

### Thread-Safety Requirements

- Multiple threads may `register()` and `lookup()` concurrently
- `register()` and `deregister()` are writes — must be exclusive
- `lookup()` and `getAllServices()` are reads — can be concurrent with other reads
- **Use a read-write lock** (Java: `ReentrantReadWriteLock`, C++: `shared_mutex`, Rust: `RwLock`, Go: `sync.RWMutex`)

### What to implement

1. **`ServiceStatus`** — Enum: UP, DOWN, STARTING
2. **`ServiceInfo`** — Immutable data class (use Builder from Ch07 if it has many fields, or a simple constructor is fine here)
3. **`ServiceRegistry`** — Singleton with read-write locking
4. **`Main`** — Demonstrate:
   - Register 3-4 services from the "main thread"
   - Look up a service by name
   - Filter services by status
   - Deregister one service
   - Print all remaining services
   - **Bonus:** Spawn 2+ threads that concurrently register and lookup services

### Expected Output

```
=== Service Registry Demo ===

Registered: user-service at localhost:8080 [UP]
Registered: order-service at localhost:8081 [UP]
Registered: payment-service at localhost:8082 [STARTING]
Registered: notification-service at localhost:8083 [DOWN]

Lookup 'order-service': order-service at localhost:8081 [UP]

Services with status UP:
  - user-service at localhost:8080
  - order-service at localhost:8081

Deregistered: payment-service
Service count: 3

All services:
  - user-service at localhost:8080 [UP]
  - order-service at localhost:8081 [UP]
  - notification-service at localhost:8083 [DOWN]
```

## Constraints

- One file per class/type
- Registry **must** be a Singleton
- Read-write lock required (not just a simple mutex on everything)
- `ServiceInfo` should be immutable once created
- Demonstrate that `getInstance()` returns the same instance from different places

## Design Hints

- **Java:** `ReentrantReadWriteLock` with `readLock()` / `writeLock()`. Store services in a `Map<String, ServiceInfo>`.
- **C++:** `std::shared_mutex` with `std::shared_lock` (read) / `std::unique_lock` (write).
- **Rust:** `RwLock<HashMap<String, ServiceInfo>>` inside `OnceLock`.
- **Go:** `sync.RWMutex` with `RLock()`/`RUnlock()` for reads, `Lock()`/`Unlock()` for writes.

## Submission

Put your solution in `08-Singleton/assignments/medium/src/{java,cpp,rust,go}/`.
