# Assignment: Document Version History (Medium)

## Objective

Build a document editor with **named version snapshots** (like Google Docs' version history), combining Memento with the **Caretaker managing multiple restore points** — not just a linear undo stack — and a note on **memory-efficient** snapshots.

## Background

Real version history isn't just "undo the last change." You can name versions ("First draft", "After review"), jump back to **any** of them, and branch forward. The document (originator) snapshots its full state; the version manager (caretaker) keeps a labeled, timestamped collection you can navigate.

## Requirements

### Originator — `Document`

State to snapshot: `title`, `body`, and a list of `tags`.

| Method | Behavior |
|--------|----------|
| `setTitle(String)`, `setBody(String)`, `addTag(String)` | mutate state |
| `save(String versionName)` | returns a `DocumentMemento` capturing a **deep copy** of the full state |
| `restore(DocumentMemento)` | replaces state from the memento |
| `describe()` | prints current title, body, tags |

> **Deep-copy requirement:** the memento must snapshot a *copy* of the tags list, not a reference — otherwise later `addTag` calls would mutate a past snapshot. This is the classic Memento pitfall; get it right.

### Memento — `DocumentMemento`

Immutable snapshot of title, body, and a **copied** tags list. Exposes only safe metadata publicly: `versionName()` and a `savedAt` timestamp/sequence number. The full state is readable only by the `Document`.

### Caretaker — `VersionHistory`

Not a simple stack — a **navigable list** of named versions:

| Method | Behavior |
|--------|----------|
| `commit(DocumentMemento)` | append a new version |
| `list()` | print all version names (+ timestamps) without exposing content |
| `getVersion(String name)` | return the memento with that name (for the document to restore) |
| `latest()` | most recent version |

### What to implement

1. `Document`, `DocumentMemento`, `VersionHistory`
2. `Main`:
   - Create a doc, set title/body, add tags, commit `"v1 - draft"`
   - Edit body, add another tag, commit `"v2 - reviewed"`
   - Edit again (uncommitted)
   - `list()` the versions
   - Restore back to `"v1 - draft"` and `describe()` — confirm tags match v1 exactly (proving the deep copy worked)

### Expected Result (shape)

```
Versions:
  v1 - draft   (saved #1)
  v2 - reviewed (saved #2)
Restoring v1 - draft...
Title: My Report
Body: First draft content
Tags: [draft, internal]
```

## Constraints

- One file per class/type in all 4 languages
- The memento must **deep-copy** mutable state (the tags list) — verify no aliasing
- `VersionHistory` exposes version names/timestamps but never the document body/tags
- The document's fields stay private; only it reads a memento's full state
- Restoring an older version must not corrupt newer versions in history

## Design Questions to Answer (in a comment)

1. Why must the tags list be **deep-copied** into the memento? What breaks if it isn't?
2. If documents were huge, how would you avoid storing a **full copy** per version? (Hint: diffs / Command-based history, or copy-on-write.)

## Submission

Put your solution in `21-Memento/assignments/medium/src/{java,cpp,rust,go}/`.
