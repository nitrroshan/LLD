# Assignment: Document Cloner (Easy)

## Objective

Apply the Prototype pattern to clone `Document` objects that contain nested mutable data.

## Requirements

Build a document system with:

**`Document`** — the prototype:

| Field | Type | Mutable? |
|-------|------|----------|
| title | String | No (immutable in Java) |
| author | String | No |
| content | String | No |
| tags | List of Strings | **Yes** — must deep copy |
| lastModified | timestamp/date | **Yes** — clone gets current time |

### What to implement

1. **`Document`** — with a copy constructor and `clone()` method
2. **Deep copy `tags`** — modifying the clone's tags must NOT affect the original
3. **`lastModified`** — the clone should get a **new** timestamp (current time), not copy the original's
4. **`Main`** — Demonstrate:
   - Create an original document with some tags
   - Clone it twice
   - Modify each clone's tags independently
   - Print all three — show the original is unchanged

### Expected Output

```
--- Original ---
Document [title=Design Patterns, author=GoF, tags=[programming, classic], modified=2026-04-05T10:00:00]

--- Clone 1 (modified) ---
Document [title=Design Patterns, author=GoF, tags=[programming, classic, recommended], modified=2026-04-05T10:00:01]

--- Clone 2 (modified) ---
Document [title=Design Patterns, author=GoF, tags=[programming, classic, archived], modified=2026-04-05T10:00:01]

--- Original (unchanged) ---
Document [title=Design Patterns, author=GoF, tags=[programming, classic], modified=2026-04-05T10:00:00]
```

## Constraints

- One file per class
- Must use **deep copy** for the tags list
- `lastModified` on the clone = current time (not copied from original)
- Document must be immutable after cloning (no setters — only the clone process sets fields)

## Key Learning

This tests whether you understand **shallow vs deep copy**. If you shallow-copy `tags`, modifying the clone's tags will corrupt the original.

## Submission

Put your solution in `09-Prototype/assignments/easy/src/{java,cpp,rust,go}/`.
