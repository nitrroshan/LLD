# Assignment: Light & Fan Remote (Easy)

## Objective

Apply the Command pattern to a remote with **multiple slots**, each controlling a different device — the classic "programmable remote" exercise.

## Background

A remote has several buttons (slots). Each slot is programmed with an `on` command and an `off` command. Pressing a button just triggers whatever command is in that slot — the remote has no idea what device it controls.

## Requirements

**Command interface — `Command`:** `execute()`, `undo()`

**Receivers (one file each):**

| Receiver | Methods |
|----------|---------|
| `Light` | `on()`, `off()` |
| `Fan` | `start()`, `stop()` |

**Concrete commands (one file each):**

| Command | execute() | undo() |
|---------|-----------|--------|
| `LightOnCommand` | `light.on()` | `light.off()` |
| `LightOffCommand` | `light.off()` | `light.on()` |
| `FanOnCommand` | `fan.start()` | `fan.stop()` |
| `FanOffCommand` | `fan.stop()` | `fan.start()` |

**Invoker — `RemoteControl`:**

- Has **2 slots** (index 0 and 1), each with an on-command and an off-command
- `setCommand(int slot, Command onCommand, Command offCommand)`
- `pressOn(int slot)` / `pressOff(int slot)` — execute the relevant command and remember it as the last action
- `pressUndo()` — undo the last action

### What to implement

1. `Command`, `Light`, `Fan`, the 4 concrete commands, `RemoteControl` — one file per type in all 4 languages
2. `Main`:
   - Slot 0 → Light on/off; Slot 1 → Fan on/off
   - Press: slot 0 on, slot 1 on, slot 0 off, then **undo** (should turn the light back on)

### Expected Output (shape)

```
Living Room light is ON
Fan is running
Living Room light is OFF
[undo]
Living Room light is ON
```

## Constraints

- One file per class/type
- `RemoteControl` depends only on `Command` — never on `Light` or `Fan` directly
- Adding a new device must not require modifying `RemoteControl`
- Consider a "no command" default so an unprogrammed slot doesn't crash (null-object is a nice touch)

## Submission

Put your solution in `18-Command/assignments/easy/src/{java,cpp,rust,go}/`.
