# Assignment: Shape Renderer (Medium)

## Objective

Combine the Bridge pattern with concepts from earlier chapters to build a shape drawing system where **shapes** and **renderers** vary independently.

## Context

A graphics application needs to draw shapes using different rendering backends. Without Bridge, you'd need `VectorCircle`, `RasterCircle`, `VectorSquare`, `RasterSquare`... and adding a new renderer or shape explodes the class count.

## Requirements

### Two Dimensions

**Abstraction — Shapes:**
- `Circle(radius)` — draws using `render_circle(x, y, radius)`
- `Square(side)` — draws using `render_rectangle(x, y, side, side)`
- `Triangle(base, height)` — draws using `render_triangle(x, y, base, height)`

Each shape has:
- `x, y` position (settable via `moveTo`)
- `draw()` — delegates to the renderer
- `resize(factor)` — scales the shape's dimensions

**Implementation — Renderers:**

```java
interface Renderer {
    void renderCircle(int x, int y, int radius);
    void renderRectangle(int x, int y, int width, int height);
    void renderTriangle(int x, int y, int base, int height);
    String getRendererName();
}
```

- `VectorRenderer` — prints `[Vector] Drawing <shape> at (x,y) with ...`
- `RasterRenderer` — prints `[Raster] Rendering <shape> pixels at (x,y) with ...`
- `SvgRenderer` — prints `[SVG] <circle cx="x" cy="y" r="radius" />` (or appropriate SVG element)

### What to implement

1. **`Renderer`** — implementation interface with methods for each primitive
2. **`VectorRenderer`**, **`RasterRenderer`**, **`SvgRenderer`** — concrete implementations
3. **`Shape`** — abstract class holding a `Renderer` reference (the bridge)
4. **`Circle`**, **`Square`**, **`Triangle`** — concrete shapes that delegate to the renderer
5. **`Main`** — demonstrate:
   - Draw each shape with each renderer (3×3 = 9 combinations, only 6 classes)
   - Move a shape and redraw — the renderer stays the same
   - Resize a shape and redraw
   - Swap renderers on the same shape (if your design allows)

### Expected Output

```
=== Shape Renderer Bridge ===

--- Circle ---
[Vector] Drawing circle at (10,20) radius=15
[Raster] Rendering circle pixels at (10,20) radius=15
[SVG] <circle cx="10" cy="20" r="15" />

--- Square ---
[Vector] Drawing rectangle at (0,0) 30x30
[Raster] Rendering rectangle pixels at (0,0) 30x30
[SVG] <rect x="0" y="0" width="30" height="30" />

--- Resize circle (2x) ---
[Vector] Drawing circle at (10,20) radius=30

--- Move and redraw ---
[Raster] Rendering circle pixels at (50,60) radius=30
```

## Constraints

- One file per class/type
- 3 shapes + 3 renderers = **6 implementation classes** (not 9)
- Shapes must delegate ALL rendering to the `Renderer` — no print statements inside shape classes
- Adding a 4th renderer should require **zero changes** to existing shapes

## Design Hints

- The `Renderer` interface has specific methods (`renderCircle`, `renderRectangle`, `renderTriangle`). Each `Shape` subclass knows which renderer method to call.
- An alternative design: `Renderer` has a single `render(ShapeData)` method — simpler but less type-safe. Use whichever feels more natural.
- Think about how `resize()` works: `Circle.resize(2)` doubles the radius, `Square.resize(2)` doubles the side.

## Submission

Put your solution in `11-Bridge/assignments/medium/src/{java,cpp,rust,go}/`.
