# Assignment: Text Formatting with Stacked Decorators (Medium)

## Objective

Combine the Decorator pattern with concepts from earlier chapters to build a **text formatter** where formatting operations (bold, italic, uppercase, etc.) are stacked as decorators.

## Context

Text editors apply formatting as layers. You start with plain text, then wrap it in bold, italic, or other formatting. Each layer transforms the text independently and can be combined freely.

## Requirements

**Component — `TextComponent`:**

| Method | Description |
|--------|-------------|
| `render()` | Returns the formatted text as a String |
| `getFormatting()` | Returns a description of applied formatting |

**Base text (Concrete Component):**
- `PlainText(content)` — stores raw text, `render()` returns it as-is

**Decorators:**

| Decorator | `render()` behavior | Example |
|-----------|-------------------|---------|
| `BoldDecorator` | Wraps in `**...**` | `**hello**` |
| `ItalicDecorator` | Wraps in `*...*` | `*hello*` |
| `UpperCaseDecorator` | Converts to UPPERCASE | `HELLO` |
| `TrimDecorator` | Removes leading/trailing whitespace | `hello` (from `"  hello  "`) |
| `BracketDecorator` | Wraps in `[...]` | `[hello]` |

### What to implement

1. `TextComponent` — component interface
2. `PlainText` — concrete component
3. All 5 decorator classes
4. `Main` — demonstrate:

```
--- Basic Decorators ---
Plain:      Hello, World!
Bold:       **Hello, World!**
Italic:     *Hello, World!*
Upper:      HELLO, WORLD!

--- Stacked Decorators ---
Bold+Italic:     ***Hello, World!***
Upper+Bold:      **HELLO, WORLD!**
Trim+Upper+Bold: **HELLO**

--- Order Matters! ---
Bold then Upper:  **HELLO, WORLD!**     ← uppercased "**Hello**" → "**HELLO**" ✗ (asterisks survive)
Upper then Bold:  **HELLO, WORLD!**     ← bold wraps uppercased text ✓

--- Formatting Chain ---
[Hello]:                [Hello, World!]
[*Hello*]:              [*Hello, World!*]
[***Hello***]:          [***Hello, World!***]
```

### Key Learning: Order Matters

```java
// Bold first, then UpperCase
Text t1 = new UpperCaseDecorator(new BoldDecorator(new PlainText("hello")));
t1.render(); // "**HELLO**" — uppercased the asterisks too!

// UpperCase first, then Bold
Text t2 = new BoldDecorator(new UpperCaseDecorator(new PlainText("hello")));
t2.render(); // "**HELLO**" — bold wraps the already-uppercased text
```

The result differs because UpperCase transforms everything including formatting markers. This demonstrates that **decorator order can change the output** — an important pitfall.

## Constraints

- One file per class/type
- Each decorator must only do ONE thing (SRP)
- Decorators must be freely combinable in any order
- `getFormatting()` returns something like `"Plain → Bold → Italic"` showing the chain

## Bonus

Add a `RepeatDecorator(n)` that repeats the text n times: `"hello"` → `"hellohellohello"` (n=3).

## Submission

Put your solution in `13-Decorator/assignments/medium/src/{java,cpp,rust,go}/`.
