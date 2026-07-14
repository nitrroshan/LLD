# Assignment: Playlist Iterator with Shuffle (Easy)

## Objective

Apply the Iterator pattern to a music playlist that supports **multiple traversal orders** over the same songs — sequential and shuffled — without the client ever seeing the internal storage.

## Background

A media player walks a playlist. Sometimes you play in order; sometimes you shuffle. The client's "play loop" should be **identical** in both cases — only the iterator differs. This is the pattern's core strength: alternative traversals behind one interface.

## Requirements

**Element — `Song`:** `title`, `artist` (a `toString`/`String()`/`Display` that prints `"<title>" by <artist>`)

**Iterator interface — `Iterator`:** `hasNext()`, `next()`

**Aggregate — `Playlist`:**

| Method | Behavior |
|--------|----------|
| `addSong(Song)` | append a song |
| `iterator()` | returns a **sequential** iterator (front to back) |
| `shuffleIterator(long seed)` | returns an iterator that yields all songs in a **shuffled** order (use the seed so results are reproducible) |

**Concrete iterators (one file each):**

- `SequentialIterator` — walks in insertion order
- `ShuffleIterator` — visits every song exactly once in a shuffled order (precompute a shuffled index list in the constructor using the seed)

### What to implement

1. `Song`, `Iterator`, `Playlist`, `SequentialIterator`, `ShuffleIterator` — one file per type in all 4 languages
2. `Main`:
   - Add 5 songs
   - Play sequentially with the same `playAll(iterator)` helper
   - Play shuffled (fixed seed) with the **same** helper
   - Confirm the shuffle yields all 5 songs exactly once (no repeats, no misses)

### Expected Output (shape)

```
Sequential:
  "Song A" by ...
  "Song B" by ...
  ... (all 5, in order)
Shuffled (seed 42):
  "Song C" by ...
  "Song A" by ...
  ... (all 5, shuffled, each once)
```

## Constraints

- One file per class/type
- `playAll(...)` must accept the `Iterator` interface and work unchanged for both orders
- The client must never access the internal song storage directly
- `ShuffleIterator` must visit **every** song exactly once — verify no duplicates or omissions

## Submission

Put your solution in `19-Iterator/assignments/easy/src/{java,cpp,rust,go}/`.
