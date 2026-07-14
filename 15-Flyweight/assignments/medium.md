# Assignment: Character Rendering Engine (Medium)

## Objective

Build a text-rendering engine that draws documents character by character, using the Flyweight pattern to share **glyph** data — and combine it with the **Factory Method** (Chapter 05) *and* a touch of **Composite** (Chapter 12) thinking for the document structure.

## Background

A word processor may render millions of characters. The **glyph** for the letter `A` in font `Arial` at size `12` is identical everywhere it appears — that's intrinsic state worth sharing. What differs per occurrence is the **position** in the document (row, column) and possibly a run-time style flag. This is exactly Flyweight at the scale it was invented for (it's the canonical GoF example).

## Part 1 — The Flyweight

**`Glyph` (intrinsic state):**

| Field | Meaning |
|-------|---------|
| `symbol` | the character, e.g. `'A'` |
| `font` | e.g. `"Arial"` |
| `size` | e.g. `12` |

Method: `draw(int row, int col)` → prints `'A' [Arial 12] at (row, col)`

**`GlyphFactory`:**

- `getGlyph(char symbol, String font, int size)` → returns a shared `Glyph`, caching by the full `(symbol, font, size)` key. Print on creation only.
- `distinctGlyphCount()`

> **Key discipline:** the cache key must include **all three** intrinsic fields. An `'A'` in Arial-12 and an `'A'` in Arial-14 are *different* flyweights.

## Part 2 — The Context

**`Character` (extrinsic state):** holds `row`, `col`, and a reference to a shared `Glyph`. Its `render()` calls `glyph.draw(row, col)`.

## Part 3 — Combine with Factory Method (Ch05)

Define a `DocumentTheme` abstraction with a factory method `createGlyphFor(char c)` that decides the font/size for a character. Two concrete themes:

| Theme | Font | Size |
|-------|------|------|
| `ClassicTheme` | `"Times New Roman"` | `12` |
| `ModernTheme` | `"Helvetica"` | `11` |

Each theme uses a **shared** `GlyphFactory` internally, so themes still benefit from flyweight sharing. `createGlyphFor` picks the theme's font/size, then delegates to the factory.

## Part 4 — The Document (Composite-flavored client)

**`Document`:**

| Method | Behavior |
|--------|----------|
| `Document(DocumentTheme theme)` | store the theme |
| `addText(String text, int row)` | for each char, use the theme to get a `Glyph`, wrap it in a `Character` at the right `(row, col)`, store it |
| `render()` | render every character in order |
| `distinctGlyphCount()` | expose the factory's count |

### What to implement

1. `Glyph`, `GlyphFactory`, `Character` — the flyweight core
2. `DocumentTheme` (interface/trait/abstract) + `ClassicTheme`, `ModernTheme` — factory method
3. `Document` — the client
4. `Main` — render the string `"HELLO HELLO HELLO"` with the `ClassicTheme`, then report the distinct glyph count

### Expected Result

- The string `"HELLO HELLO HELLO"` (17 chars incl. spaces) creates **only the distinct glyphs**: `H, E, L, O, <space>` = **5** distinct glyphs, even though 17 `Character` contexts exist.
- Rendering shows all 17 characters at their positions.

```
Characters rendered:  17
Distinct glyphs:      5
```

## Constraints

- One file per class/type in all 4 languages
- `Glyph` is immutable; position is never stored in it
- All glyph creation flows through `GlyphFactory` (the themes share one factory)
- No `instanceof`/type switches in `Document` — the theme's factory method hides font choice

## Stretch Goal (optional)

Add a `bold` boolean as **extrinsic** state on `Character` (not on `Glyph`), and have `render()` print `(bold)` when set — proving you can vary appearance per-occurrence without creating new flyweights.

## Submission

Put your solution in `15-Flyweight/assignments/medium/src/{java,cpp,rust,go}/`.
