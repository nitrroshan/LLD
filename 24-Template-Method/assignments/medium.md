# Assignment: Game Turn Framework (Medium)

## Objective

Build a turn-based game framework where the **turn structure** is fixed by a template method, but each game type fills in the specifics — and combine Template Method with the **Strategy** pattern (Ch22) for a pluggable AI move-selection, so you can directly feel the difference between the two patterns.

## Background

Many turn-based games share a turn skeleton: start turn → the player acts → resolve effects → check win → end turn. Chess, checkers, and tic-tac-toe differ in *how* a move is made and *how* a win is checked, but the turn *flow* is identical. Template Method fixes the flow; each game overrides the varying steps. Layering **Strategy** on top lets the "player acts" step swap between a human and different AI difficulties at runtime.

## Part 1 — Template Method: the turn skeleton

**Abstract `Game`:**

Template method `playTurn(int player)` runs, in order:
1. `startTurn(player)` — concrete: prints `-- Player <player>'s turn --`
2. `makeMove(player)` — **abstract**: game-specific move
3. `applyEffects()` — hook: default does nothing (some games override)
4. `isGameOver()` — **abstract**: returns bool
5. `endTurn(player)` — concrete: prints `-- end turn --`

Also a concrete `play()` loop that alternates players calling `playTurn` until `isGameOver()` (cap at a few turns for the demo).

**Concrete games (one file each):**

| Game | makeMove | isGameOver |
|------|----------|------------|
| `TicTacToe` | `Player <p> marks a square` | true after 3 moves (demo) |
| `Checkers` | `Player <p> moves a piece` | true after 4 moves (demo); overrides `applyEffects()` to print `Removing captured pieces` |

## Part 2 — Strategy: pluggable move selection (Ch22)

Give one game a **`MoveStrategy`** used inside `makeMove`:

- `MoveStrategy` interface: `chooseMove(int player) String`
- `RandomAiStrategy` → returns `"random move"`
- `GreedyAiStrategy` → returns `"greedy move"`

`TicTacToe.makeMove` delegates to its current `MoveStrategy` and prints `Player <p> plays a <chosen>`. The strategy can be swapped at runtime.

### What to implement

1. `Game` (abstract/base/trait) with the template method + `play()` loop
2. `TicTacToe` (uses a `MoveStrategy`), `Checkers` (overrides the effects hook)
3. `MoveStrategy` + `RandomAiStrategy` + `GreedyAiStrategy`
4. `Main`:
   - Play a `Checkers` game (shows the effects hook firing)
   - Play a `TicTacToe` game with `RandomAiStrategy`, then swap to `GreedyAiStrategy` and play again

### Expected Result (shape)

```
=== Checkers ===
-- Player 1's turn --
  Player 1 moves a piece
  Removing captured pieces
-- end turn --
... (alternating until game over)

=== TicTacToe (random AI) ===
-- Player 1's turn --
  Player 1 plays a random move
-- end turn --
...

=== TicTacToe (greedy AI) ===
-- Player 1's turn --
  Player 1 plays a greedy move
...
```

## Constraints

- One file per class/type in all 4 languages
- The turn order lives only in the template method; games can't reorder it
- `applyEffects()` is a hook (default no-op), not a required step
- The AI selection is a **Strategy** (swappable at runtime) — contrast this with the fixed, subclass-bound steps of the template method
- Use each language's idiom for both patterns

## Design Question to Answer (in a comment)

In one short paragraph: **which parts are Template Method and which are Strategy, and why?** Specifically, why is the *turn flow* a template method (inheritance, fixed) while the *AI move choice* is a strategy (composition, swappable)?

## Submission

Put your solution in `24-Template-Method/assignments/medium/src/{java,cpp,rust,go}/`.
Include your answer to the design question.
