# Chapter 38 — Assignment (Medium)

## En Passant + a Minimax AI opponent

A **design + implementation** exercise combining **Command** (a tricky special capture),
**history** (the command stack), and **Strategy/search** (an AI that drives make/unmake).

### Part A — En Passant

If a pawn advances two squares and lands beside an enemy pawn, that enemy may capture it
"in passing" — moving diagonally **behind** the two-square pawn and removing it, even though
the captured pawn is **not** on the destination square.

Requirements:
- Add an `EnPassantCommand` (a `Command`) whose captured pawn sits on a **different square**
  than the move's destination; `execute()` removes it, `undo()` restores it.
- Legality depends on the **immediately preceding move** being the enemy pawn's two-square
  advance. Use the **history stack** (the `MoveCommand`s you already record) to check the
  last move — this is exactly why history is a stack of command objects.
- Only legal on the very next move; otherwise the right is lost.

Design note to answer: en passant is the clearest case where "a move needs to know the
previous move." Explain how the Command history makes this clean, versus storing ad-hoc flags.

### Part B — Minimax AI

Give the engine an AI that picks a move for one side (reuse the Ch31 Tic-Tac-Toe idea).

Requirements:
- Add a board **evaluation** function: material count (P=1, N=B=3, R=5, Q=9) from the side to
  move's perspective; optionally small positional bonuses.
- Implement **minimax with alpha-beta pruning** to a fixed depth (e.g., 3). Crucially, it must
  **make and unmake** moves using the existing `MoveCommand.execute()`/`undo()` — **do not
  copy the board**. That's the payoff of the Command pattern for search.
- Expose it as an `AiPlayer` / `MoveStrategy` that, given a `Game`, returns the best
  `(from, to)`; the demo lets the AI answer the opponent's moves.
- Generate candidate moves by reusing the legal-move logic (the same `hasAnyLegalMove` scan,
  but returning the moves).

### Part C — Design write-up

In a short `DESIGN.md` (or comments), explain:
- Why make/unmake (Command undo) beats copying the board for search performance.
- How en passant and castling both fit as `Command` subtypes without touching the core loop.

### Constraints

- En passant is a **new `Command`**; the AI **reuses** `execute()`/`undo()` — no board copying.
- Keep the search depth small so the demo runs quickly; correctness over strength.

### Demo (extend `Main` / `main.cpp`)

1. Set up an en-passant position (White pawn to the 5th rank, Black answers with an adjacent
   two-square advance) and perform the en-passant capture; `undo()` and show both pawns back.
2. Play a few moves where the **AI** chooses the reply, printing its selected move and the
   evaluation.

### What good looks like

- En passant is a `Command` that consults the history for the previous move.
- The AI searches via make/unmake on the real board (no copies), proving why moves-as-commands
  scale to game-tree search.
- A crisp note tying it together: Command → undo → both special moves *and* AI search.
