# Assignment: Pluggable Rules + Replay (Design + Code)

## Objective

Make the **game rules pluggable** via a Strategy, and record a full **replay** of the game via an observer — so the same engine can play many rule variants and the match can be re-watched. Implement in **Java and C++**.

## Part 1 — Rule Strategy

Extract the variable rules into a `RuleSet` (Strategy):

```
interface RuleSet {
    boolean grantsExtraTurn(int diceRoll, Dice dice);   // e.g. extra turn on max
    boolean isWinningMove(int destination, int boardSize); // exact vs any >= size
    int resolveOvershoot(int from, int roll, int boardSize); // stay, bounce back, or wrap
}
```

Provide at least two rule sets:
- `ClassicRules` — exact win, overshoot stays, no extra turns.
- `FastRules` — win on reaching-or-passing the last cell, extra turn on max roll, overshoot bounces back.

`Game` delegates these decisions to the injected `RuleSet` — swapping rules must not change `Game`'s core loop.

## Part 2 — Replay Recorder (Observer)

Add a `ReplayRecorder` observer that captures every event into an ordered log. After the game, it can **print the full replay** (turn-by-turn) and report the winner and total turns. This shows an observer that *stores* rather than just prints.

## Design Tasks (answer in `DESIGN.md`)

1. Why is the rule variation a **Strategy** and the replay a **Observer**? Could either be done with the other pattern, and what would you lose?
2. `RuleSet` needs game context (board size, dice) to decide. How do you pass just enough context without coupling `RuleSet` to the whole `Game`?
3. The replay recorder and the console logger both observe the same events. What does this demonstrate about the Observer pattern's value here?

## Implementation Requirements

- `RuleSet` + `ClassicRules` + `FastRules`; `Game` delegates win/overshoot/extra-turn decisions to it.
- `ReplayRecorder` observer that logs events and can print the whole game afterward.
- Demo: run the **same board and seed** under `ClassicRules` and `FastRules`, and show the replay for one of them — the different rules produce different games from identical inputs.

## Constraints

- One file per class/type in **Java and C++**
- Swapping the `RuleSet` must not modify `Game`'s turn loop (OCP)
- `Game` keeps no rule logic of its own — it asks the `RuleSet`
- The replay recorder must not print during play (only capture); it prints on demand afterward

## Design Question to Answer

You now have three plug-in axes: **board elements** (Factory), **rules** (Strategy), and **reporting** (Observer). Explain in a short paragraph how these three keep `Game` small and closed for modification while the system stays open for extension.

## Submission

Put your solution in `32-Snake-And-Ladder/assignments/medium/src/{java,cpp}/` with a short `DESIGN.md`.
