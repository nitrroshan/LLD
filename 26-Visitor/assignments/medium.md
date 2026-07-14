# Assignment: File System Reports (Medium)

## Objective

Build a file-system tree and run multiple reporting operations over it with the Visitor pattern, **combined with Composite** (Ch12) — the classic pairing where a visitor walks a composite structure.

## Background

A file system is a Composite: `File` (leaf) and `Directory` (holds children). You want several reports over it — total size, a count of files by extension, a printed tree — without stuffing all that logic into `File`/`Directory`. Each report is a visitor; the composite structure is traversed by the visitors.

## Part 1 — The Composite elements (Ch12)

**Element — `FileSystemNode`:** `accept(FileSystemVisitor visitor)`

| Node | Data |
|------|------|
| `File` | `name`, `size` (bytes), and derives its extension from the name |
| `Directory` | `name`, `children` (list of `FileSystemNode`) |

**Visitor — `FileSystemVisitor`:** `visitFile(File)`, `visitDirectory(Directory)`

`Directory.accept` calls `visitor.visitDirectory(this)`; the visitor decides whether/how to recurse into children (this keeps traversal control in the visitor).

## Part 2 — The reporting visitors (one file each)

| Visitor | Behavior |
|---------|----------|
| `SizeVisitor` | accumulates the total size of all files in the tree |
| `ExtensionCountVisitor` | builds a map of `extension -> count` across all files |
| `TreePrintVisitor` | prints the tree with indentation (directories then their children) |

Each visitor recurses into a directory's children itself (call `child.accept(this)` for each child).

### What to implement

1. `FileSystemNode`, `File`, `Directory` (Composite)
2. `FileSystemVisitor` + `SizeVisitor` + `ExtensionCountVisitor` + `TreePrintVisitor`
3. `Main`: build this tree and run all three visitors:

```
root/
├── main.java     (500)
├── util.java     (300)
├── README.md     (100)
└── docs/
    ├── guide.md  (200)
    └── logo.png  (900)
```

### Expected Result (shape)

```
Tree:
  root/
    main.java (500)
    util.java (300)
    README.md (100)
    docs/
      guide.md (200)
      logo.png (900)
Total size: 2000 bytes
Extensions: {java=2, md=2, png=1}
```

## Constraints

- One file per class/type in all 4 languages
- No reporting logic inside `File`/`Directory` — only in the visitors
- Traversal (recursing into children) is done by the visitors, not baked into a fixed walk
- Adding a new report must require **no** change to `File`/`Directory`
- `TreePrintVisitor` must indent nested directories correctly (track depth in the visitor)

## Design Questions to Answer (in a comment)

1. Which pattern provides the **structure** (the tree) and which provides the **operations** (the reports)? How do they combine?
2. Visitor makes adding *operations* easy but adding *element types* hard. If you later needed to add a `Symlink` node type, what would you have to change, and why?

## Stretch Goal (optional)

Add a `SearchVisitor` that collects the paths of all files whose name matches a predicate (e.g., ends in `.md`), demonstrating a visitor that carries a parameter and returns a collection.

## Submission

Put your solution in `26-Visitor/assignments/medium/src/{java,cpp,rust,go}/`.
