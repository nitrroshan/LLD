# Assignment: Logger Singleton (Easy)

## Objective

Create a **Logger** singleton that all parts of an application share.

## Requirements

Build a `Logger` class with:

| Field | Type | Description |
|-------|------|-------------|
| logLevel | enum (DEBUG, INFO, WARN, ERROR) | Minimum level to output |
| logCount | int | Running count of messages logged |

### Methods

| Method | Description |
|--------|-------------|
| `getInstance()` | Returns the single Logger instance |
| `setLevel(level)` | Sets the minimum log level |
| `debug(message)` | Logs if level <= DEBUG |
| `info(message)` | Logs if level <= INFO |
| `warn(message)` | Logs if level <= WARN |
| `error(message)` | Always logs (ERROR is highest) |
| `getLogCount()` | Returns total messages logged so far |

### Behavior

- Log format: `[LEVEL] message`
- Messages below the current level are silently ignored (not counted)
- `logCount` only increments for messages that are actually printed

### What to implement

1. **`LogLevel`** — Enum with DEBUG, INFO, WARN, ERROR (in ascending severity)
2. **`Logger`** — Singleton with the methods above. Use Bill Pugh (Java), Meyer's (C++), OnceLock (Rust), or sync.Once (Go).
3. **`Main`** — Demonstrate:
   - Get the logger from two different places → same instance
   - Set level to INFO → debug messages are ignored
   - Log some messages at each level
   - Print the log count
   - Change level to ERROR → only errors are printed
   - Log more messages → verify count only increments for printed ones

### Expected Output

```
[INFO] Application started
[WARN] Disk space low
[ERROR] Connection failed
Log count: 3

Changing level to ERROR...
[ERROR] Critical failure
Log count: 4
```

(DEBUG message was silently ignored since level was INFO)

## Constraints

- One file per class/type
- Logger must be a proper Singleton — private constructor, static instance
- Must be **thread-safe** (use the idiomatic approach for each language)

## Submission

Put your solution in `08-Singleton/assignments/easy/src/{java,cpp,rust,go}/`.
