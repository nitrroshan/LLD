# Assignment: Filtered & Tree Iterators (Medium)

## Objective

Build two more advanced iterators — a **filtered iterator** that yields only elements matching a predicate, and a **tree iterator** that traverses a hierarchy depth-first — combining the Iterator pattern with **Composite** (Chapter 12).

## Part 1 — Filtered Iterator (decorating an iterator)

A filtered iterator **wraps another iterator** and only yields elements that pass a test. Note this is Iterator + a touch of **Decorator** (Ch13): it has the same `Iterator` interface but adds filtering.

**Requirements:**

- `Iterator` interface: `hasNext()`, `next()`
- A collection of `Product` (`name`, `price`, `inStock` boolean)
- `FilterIterator` — constructed with an underlying `Iterator` and a predicate (a function/lambda `Product -> boolean`); yields only matching products
  - Key challenge: `hasNext()` must **look ahead** to the next matching element (buffer it), skipping non-matches, so `hasNext()`/`next()` stay consistent

**Demonstrate:**
- All products
- Only in-stock products (`p -> p.inStock`)
- Only products under $50 (`p -> p.price < 50`)

Using the **same** print loop for each — only the iterator changes.

## Part 2 — Tree Iterator (Iterator + Composite, Ch12)

A file-system tree where each node is a file or a folder (folders contain children). Provide a **depth-first iterator** that visits every node without the client knowing the tree shape.

**Requirements:**

- `FileNode` — `name`, `isDirectory`, `children` (list; empty for files)
- `DepthFirstIterator` — visits root, then recursively each child (pre-order). Implement iteratively with an explicit **stack** so it's a true external iterator (not recursion that yields all at once)
- The client prints every node's name via `hasNext()`/`next()`

**Demonstrate** traversing a small tree:

```
root/
├── src/
│   ├── main.java
│   └── util.java
└── README.md
```

Expected visit order (pre-order DFS): `root, src, main.java, util.java, README.md`.

### What to implement

1. `Iterator`, `Product`, a product collection + `FilterIterator`
2. `FileNode` + `DepthFirstIterator`
3. `Main` demonstrating filtered iteration and depth-first tree iteration

### Expected Result (shape)

```
--- Filtered: in stock ---
  <matching products only>
--- Filtered: under $50 ---
  <matching products only>
--- Tree (depth-first) ---
  root
  src
  main.java
  util.java
  README.md
```

## Constraints

- One file per class/type in all 4 languages
- Both new iterators implement the **same** `Iterator` interface as before
- `FilterIterator.hasNext()` must correctly look ahead (no skipped or double-yielded elements)
- `DepthFirstIterator` must be a true external iterator (explicit stack, `hasNext`/`next` driven by the client — not "collect all into a list then iterate")
- Clients never inspect the tree structure or the underlying collection directly

## Stretch Goal (optional)

Add a `BreadthFirstIterator` (uses a queue instead of a stack) and show it visits the same tree in level order: `root, src, README.md, main.java, util.java`.

## Submission

Put your solution in `19-Iterator/assignments/medium/src/{java,cpp,rust,go}/`.
