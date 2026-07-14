# Chapter 41 — Assignment (Easy)

## JSON output + a sampling handler

A **design + implementation** exercise reinforcing **Strategy** (Formatter) and **Chain of
Responsibility**. Both additions are *additive* — no change to `Logger`.

### Part A — Use the JSON formatter

`JsonFormatter` already exists. Prove the **Formatter** Strategy works by making one appender
emit JSON.

Requirements:
- Configure the chain so the **file** handler uses `JsonFormatter` while the **console**
  handler keeps `SimpleFormatter`. The *same* `FileAppender` now emits JSON just by swapping
  the formatter — no appender change.
- Log a WARN and an ERROR and show the console line is plain text while the file line is JSON.

Design question to answer: formatting (*how a line looks*) and appending (*where it goes*) are
separate axes. Explain how keeping them as independent strategies avoids an M×N explosion
(`JsonToFile`, `TextToFile`, `JsonToConsole`, …).

### Part B — `SamplingHandler` (Chain of Responsibility)

Noisy repeated logs should be thinned out.

Requirements:
- Add a `SamplingHandler` that sits in the chain and forwards only **1 in N** records of a
  given level (e.g., sample DEBUG at 1/10), passing others **without forwarding** (they're
  dropped from everything downstream). Records at or above a "never-drop" level (e.g., ERROR)
  always pass.
- It must implement the same handler contract (`handle` + `next`), so it drops into the chain
  anywhere. Place it **before** the console handler and show it thins DEBUG while letting
  ERROR through.

Design question to answer: because a chain node can choose **not** to forward, it can drop a
record for the *entire* rest of the chain. Contrast this with a flat list of appenders — why is
"stop propagation" easier to express in a Chain of Responsibility?

### Constraints

- Formatter swap and the sampling handler are **additive**; `Logger` is unchanged.
- The sampling handler decides per-record whether to forward — it must be a real chain node.

### Demo (extend `Main` / `main.cpp`)

1. Build a chain with a JSON-formatted file handler + text console handler; log WARN/ERROR and
   show the two formats side by side.
2. Insert a `SamplingHandler(DEBUG, 1/5)` at the head; log 5 DEBUGs and 1 ERROR; show ~1 debug
   passes while the error always does.

### What good looks like

- One appender emits JSON purely by swapping the formatter (Strategy).
- Sampling is a chain node that can halt propagation — a clean fit for CoR.
- A clear articulation of the formatter/appender split and CoR's stop-propagation power.
