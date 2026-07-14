# Chapter 38 — Assignment (Easy)

## Add Castling and Pawn Promotion

A **design + implementation** exercise reinforcing **Command** and **Strategy**. Both
special moves must slot in as *new Commands* without rewriting the core `makeMove` loop.

### Part A — Pawn Promotion

When a pawn reaches the far rank (row 7 for White, row 0 for Black), it becomes another
piece (usually a queen).

Requirements:
- Add a `PromotionCommand` (a `Command`) — or extend `MoveCommand` — that, on `execute()`,
  performs the pawn move **and** replaces the pawn with a chosen `PieceType` (default
  `QUEEN`) built via `PieceFactory`.
- `undo()` must restore the **pawn** (and any captured piece) — so remember what was there.
- The `Game` should detect a pawn reaching the last rank and use the promotion command
  instead of a plain move.

Design note to answer: why is `Command.undo()` the natural place to make promotion
reversible, and what state must the command remember?

### Part B — Castling

The king moves two squares toward a rook, and that rook jumps to the king's other side.

Requirements:
- Add a `CastlingCommand` that moves **both** the king and the rook, and `undo()`s both.
- Legality rules to enforce (this is where the existing `Piece.hasMoved` flag pays off):
  1. Neither the king nor that rook has moved (`hasMoved == false`).
  2. All squares between them are empty.
  3. The king is **not currently in check**, and does **not pass through or land on** an
     attacked square (reuse `board.isSquareAttacked(...)`).
- Wire king-side castling at minimum; queen-side is a bonus.

### Constraints

- **Do not rewrite** the movement strategies or the main validation flow for these — they
  are new `Command` types plus a small amount of rule-checking.
- Reuse `isSquareAttacked` for the castling safety checks — don't duplicate attack logic.

### Demo (extend `Main` / `main.cpp`)

1. Promote a pawn: march a pawn to the last rank (clear a file first) and show it becomes a
   queen; then `undo()` and show the pawn is back.
2. Castle king-side after clearing the knight and bishop; show the king and rook both moved;
   `undo()` and show both restored.

### What good looks like

- Castling and promotion are each **new `Command` classes**; `makeMove`'s structure is
  intact.
- `undo()` fully reverses both special moves (the whole point of modeling moves as commands).
- Castling safety reuses `isSquareAttacked` — the "king doesn't pass through check" rule.
