# Assignment: Shape Visitors (Easy)

## Objective

Apply the Visitor pattern to a set of shapes, adding two operations — **area calculation** and **SVG export** — without putting either operation inside the shape classes.

## Background

You have `Circle`, `Rectangle`, and `Triangle`. You want to compute total area *and* export shapes to SVG *and* maybe more later. Baking all these into the shapes bloats them. A visitor per operation keeps each concern in one place and leaves the shapes untouched.

## Requirements

**Element — `Shape`:** `accept(ShapeVisitor visitor)`

**Concrete shapes (one file each):**

| Shape | Data |
|-------|------|
| `Circle` | `radius` |
| `Rectangle` | `width`, `height` |
| `Triangle` | `base`, `height` |

**Visitor — `ShapeVisitor`:** `visitCircle(Circle)`, `visitRectangle(Rectangle)`, `visitTriangle(Triangle)`

**Concrete visitors (one file each):**

| Visitor | Behavior |
|---------|----------|
| `AreaVisitor` | accumulates total area (`πr²`, `w·h`, `½·b·h`) |
| `SvgExportVisitor` | builds an SVG string per shape, e.g. `<circle r="5"/>`, `<rect w="4" h="3"/>`, `<triangle b="6" h="2"/>` |

### What to implement

1. `Shape`, `ShapeVisitor`, the 3 shapes, `AreaVisitor`, `SvgExportVisitor` — one file per type in all 4 languages
2. `Main`:
   - Put a `Circle(5)`, `Rectangle(4, 3)`, `Triangle(6, 2)` in a list
   - Run `AreaVisitor` over all → print the total area
   - Run `SvgExportVisitor` over all → print each shape's SVG

### Expected Output (shape)

```
Total area: 96.54   (78.54 + 12 + 6)
SVG:
  <circle r="5"/>
  <rect w="4" h="3"/>
  <triangle b="6" h="2"/>
```

## Constraints

- One file per class/type
- No area or SVG logic inside the shape classes — it lives in the visitors
- Adding a third operation (e.g., a `PerimeterVisitor`) must require **no** change to the shapes
- Use each language's idiom (C++ overloaded `visit`, Go/Java named visits, Rust trait-object visitor or note the enum+match alternative)

## Submission

Put your solution in `26-Visitor/assignments/easy/src/{java,cpp,rust,go}/`.
