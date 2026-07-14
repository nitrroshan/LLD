# Assignment: Generalized M×N, K-in-a-Row (Design + Code)

## Objective

Generalize the game to an **M×N board** where a win is **K in a row** (horizontal, vertical, or diagonal) — like Gomoku / Connect-style rules — by extracting the win check into its own **strategy**. Implement in **Java and C++**.

## Background

The current `Board.getWinner()` assumes a square board and a full line. Real variants decouple *board shape* from *win condition*: a 6×7 board with K=4 (Connect Four style, ignoring gravity), a 15×15 board with K=5 (Gomoku). Make the win rule pluggable.

## Part 1 — Win-Condition Strategy

Introduce `WinCondition` (a Strategy):

```
interface WinCondition {
    Symbol check(Board board, Move lastMove);   // winner symbol, or EMPTY
}
```

- `KInARowCondition(k)` — after `lastMove`, scan the four directions (─ │ ╲ ╱) through that cell and report a win if `k` consecutive same symbols occur.
- Checking only around `lastMove` (not the whole board) is the efficient, idiomatic approach — note why.

`Board` (or `Game`) holds a `WinCondition` and delegates the check to it.

## Part 2 — Rectangular Board

- `Board(rows, cols)` — non-square. `availableMoves`, `isFull`, `copy`, and `display` must all handle M×N.
- The AI strategies must still work (they use `availableMoves` and `getWinner`/`WinCondition` — keep them decoupled from board shape).

## Design Tasks (answer in `DESIGN.md`)

1. Why extract the win check into a **Strategy** instead of adding parameters to `Board.getWinner()`? What does it buy you (think Connect Four, Gomoku, misère variants)?
2. Why check only around `lastMove` rather than re-scanning the whole board each turn? What changes in the `Board`/`Game` interface to make `lastMove` available?
3. Your `RuleBasedAiStrategy` hard-codes center/corner heuristics that assume a small square board. How would you make the AI's heuristics **board-shape-agnostic**, or swap in a different heuristic per board size?

## Implementation Requirements

- `WinCondition` + `KInARowCondition(k)`; `Board`/`Game` delegates to it.
- `Board` supports M×N (rows ≠ cols).
- Demo: a 3×3 K=3 game (classic) and a 5×5 K=4 game, both driven by the same `Game`, differing only in board size and win condition.

## Constraints

- One file per class/type in **Java and C++**
- Adding a new win rule or board size must not modify `Game` or the move strategies (OCP)
- The win check must be efficient (localized to the last move) for larger boards
- Keep move-selection (Strategy) and win-detection (Strategy) as independent axes

## Stretch Goal (optional)

Add **gravity** (Connect Four): a move specifies only a column, and the piece falls to the lowest empty row. Model this as a `MoveRule`/board variant without breaking the existing games.

## Submission

Put your solution in `31-Tic-Tac-Toe/assignments/medium/src/{java,cpp}/` with a short `DESIGN.md`.
