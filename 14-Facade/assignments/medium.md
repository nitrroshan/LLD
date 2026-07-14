# Assignment: Computer Startup Facade (Medium)

## Objective

Model the boot sequence of a computer with a Facade, and combine it with the **Factory Method** pattern (Chapter 05) so the facade can boot different machine types.

## Background

Booting a computer is a multi-step subsystem dance: power up the CPU, load the boot sector from disk into memory, then hand control to the OS. You'll hide this behind a `ComputerFacade`, and use a factory so the *same* facade can start a `GamingPc` or a `Server` without the client knowing the difference.

## Part 1 — The Subsystem

Implement these subsystem classes (one file each):

| Class | Method | Prints |
|-------|--------|--------|
| `Cpu` | `freeze()` | `CPU: freezing processor` |
| `Cpu` | `jump(position)` | `CPU: jumping to position <position>` |
| `Cpu` | `execute()` | `CPU: executing instructions` |
| `Memory` | `load(position, data)` | `Memory: loading '<data>' at position <position>` |
| `HardDrive` | `read(lba, size)` | returns the string `boot data (<size> bytes)`; prints `HardDrive: reading <size> bytes from LBA <lba>` |

## Part 2 — The Facade

`ComputerFacade` holds a `Cpu`, `Memory`, and `HardDrive`. Its `start()` method runs:

```
1. cpu.freeze()
2. data = hardDrive.read(BOOT_SECTOR, SECTOR_SIZE)
3. memory.load(BOOT_ADDRESS, data)
4. cpu.jump(BOOT_ADDRESS)
5. cpu.execute()
```

Use constants: `BOOT_SECTOR = 0`, `BOOT_ADDRESS = 1024`, `SECTOR_SIZE = 512`.

## Part 3 — The Factory (combine with Chapter 05)

Define a `Computer` abstraction with a `boot()` method. Two concrete computers:

| Type | `boot()` prints (before running the facade) |
|------|---------------------------------------------|
| `GamingPc` | `Booting Gaming PC...` |
| `Server` | `Booting Server...` |

Each concrete computer **owns a `ComputerFacade`** and calls `facade.start()` inside `boot()`.

A `ComputerFactory` with a factory method `create(type)` returns the right `Computer` given a type (`"gaming"` or `"server"`).

### What to implement

1. `Cpu`, `Memory`, `HardDrive` — subsystem (one file each)
2. `ComputerFacade` — the boot sequence
3. `Computer` (interface/trait/abstract) + `GamingPc`, `Server`
4. `ComputerFactory` — factory method returning a `Computer`
5. `Main` — use the factory to create and boot a gaming PC, then a server

### Expected Output

```
Booting Gaming PC...
CPU: freezing processor
HardDrive: reading 512 bytes from LBA 0
Memory: loading 'boot data (512 bytes)' at position 1024
CPU: jumping to position 1024
CPU: executing instructions

Booting Server...
CPU: freezing processor
HardDrive: reading 512 bytes from LBA 0
Memory: loading 'boot data (512 bytes)' at position 1024
CPU: jumping to position 1024
CPU: executing instructions
```

## Constraints

- One file per class/type in all 4 languages
- The client only calls `factory.create(type)` then `computer.boot()` — it never touches the subsystem or the facade directly
- The facade only coordinates; keep the boot logic out of `Main`
- No `instanceof` / type switches in client code — the factory hides the concrete type

## Stretch Goal (optional)

Add a `shutdown()` to the facade that reverses the sequence (`cpu` halts, memory clears) and call it from `boot()`'s cleanup path.

## Submission

Put your solution in `14-Facade/assignments/medium/src/{java,cpp,rust,go}/`.
