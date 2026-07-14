# Assignment: Task Scheduler (Hard)

## Objective

Build a **task scheduler** that treats jobs as command objects — queuing them, running them in order, retrying failures, and combining the Command pattern with **Factory Method** (Ch05) and **Composite** (via macro/batch jobs, Ch12). This is an open-ended design problem.

## Background

A scheduler accepts jobs, holds them in a queue, and runs them when told. Jobs are commands: each knows how to `execute()` and how to `undo()` (compensate). Some jobs are **batches** of sub-jobs. Jobs can **fail**, and the scheduler should support a retry policy and a rollback of a failed batch.

## Requirements

### Part 1 — Job command

**`Job` interface:** `execute() boolean` (returns success), `undo()`, `name() String`

**Concrete jobs (at least two, one file each):**

| Job | execute() behavior |
|-----|--------------------|
| `EmailJob` | prints `Sending email to <to>`; returns success |
| `ReportJob` | prints `Generating report <name>`; returns success |
| `FlakyJob` | fails the first N times, then succeeds — to exercise retries |

### Part 2 — Batch job (Composite)

**`BatchJob implements Job`:** holds a list of jobs.
- `execute()` runs sub-jobs in order; if any fails, **undo the ones already done** (in reverse) and report batch failure
- `undo()` undoes all sub-jobs in reverse order

### Part 3 — Job factory (Factory Method, Ch05)

**`JobFactory`** with `create(String type, ...params)` returning the right `Job`. The scheduler and client create jobs through the factory, not with direct constructors.

### Part 4 — The scheduler (Invoker)

**`Scheduler`:**

| Method | Behavior |
|--------|----------|
| `submit(Job job)` | enqueue a job |
| `run()` | dequeue and execute jobs in FIFO order; keep a history of successful jobs |
| `setRetryPolicy(int maxRetries)` | on failure, retry a job up to `maxRetries` times before giving up |
| `undoLast()` | undo the most recently completed job |
| `undoAll()` | undo all completed jobs in reverse order |

### What to implement

1. `Job` + concrete jobs + `BatchJob`
2. `JobFactory`
3. `Scheduler` with queue, history, and retry policy
4. `Main` demonstrating:
   - Submitting several jobs (including a `BatchJob` and a `FlakyJob`)
   - Running the queue with a retry policy that lets the flaky job eventually succeed
   - A batch where one sub-job fails → the batch rolls back
   - `undoAll()` at the end

## Design Questions to Answer (in comments or a short note)

1. Why is a **queue** of commands more flexible than direct method calls here?
2. How does **retry** stay clean because jobs are command objects?
3. Where does **Composite** appear, and why is undo done in **reverse**?
4. How would you add **persistence** (save the queue to disk and resume later) given commands are objects?

## Constraints

- One file per class/type in all 4 languages
- `Scheduler` depends only on the `Job` interface
- The factory hides concrete job construction
- Batch rollback and scheduler undo must both unwind in reverse order
- No job is silently lost or double-executed

## Submission

Put your solution in `18-Command/assignments/hard/src/{java,cpp,rust,go}/`.
Include your answers to the four design questions.
