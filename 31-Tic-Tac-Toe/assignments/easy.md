# Assignment: Human Input + Unbeatable AI (Design + Code)

## Objective

Add a real **interactive human player** and an **unbeatable minimax AI**, both as new `MoveStrategy` implementations — proving the game needs no changes to support them. Implement in **Java and C++**.

## Part 1 — Human Move Strategy

Add `HumanMoveStrategy` that reads a move from **standard input** (e.g., prompts `Enter row col:` and parses two integers), re-prompting until the input is a valid, empty cell. This replaces the `ScriptedMoveStrategy` stand-in with true human play.

## Part 2 — Minimax AI

Add `MinimaxStrategy` — a perfect player that never loses on a 3×3 board:

- Recursively evaluate each available move: score a win as `+1`, a loss as `-1`, a draw as `0` (from the current player's perspective), maximizing your outcome and minimizing the opponent's.
- Reuse `Board.copy()` for the recursion (no mutation of the live board).
- Pick the move with the best minimax score.

## Design Tasks (answer in `DESIGN.md`)

1. Why did adding two very different players (human I/O, minimax search) require **no change** to `Game`, `Player`, or `Board`? Name the pattern and the principle.
2. Minimax needs to know "whose turn is it" during recursion. How do you track the maximizing vs minimizing player cleanly without leaking turn state into `Board`?
3. `HumanMoveStrategy` does I/O; the AI strategies are pure. Does mixing an I/O strategy with pure ones cause any design smell? How would you keep `Game` testable?

## Implementation Requirements

- `HumanMoveStrategy` (stdin) and `MinimaxStrategy`.
- Add `HUMAN` and `MINIMAX` to `PlayerType` / the factory.
- Demo: Human vs Minimax (interactive), and Minimax vs Minimax (always a draw on 3×3).

## Constraints

- One file per class/type in **Java and C++**
- No changes to `Game`, `Board`, or `Player` beyond the factory's new cases
- Minimax must use board copies, not mutate the live board
- The human strategy must reject invalid/occupied cells and re-prompt

## Submission

Put your solution in `31-Tic-Tac-Toe/assignments/easy/src/{java,cpp}/` with a short `DESIGN.md`.
