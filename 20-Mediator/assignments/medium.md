# Assignment: Smart Home Controller (Medium)

## Objective

Build a smart-home hub where devices react to each other's state changes **through a central controller** (mediator), and combine it with the **Observer**-style notification idea plus a light **Command** touch (Ch18) for the actions the hub triggers.

## Background

In a smart home, events cascade: motion is detected → lights turn on and the thermostat wakes; the door locks at night → lights dim. If every device wired itself to every other device, adding one gadget would mean editing them all. A `SmartHomeHub` mediator centralizes the rules so devices stay dumb and independent.

## Requirements

### Devices (Colleagues)

Each device knows only the hub. When its state changes, it notifies the hub; the hub decides what else should happen.

| Device | State / Events |
|--------|----------------|
| `MotionSensor` | `detectMotion()` → notifies hub with event `"motion"` |
| `Light` | `turnOn()`, `turnOff()`, `dim(int percent)` |
| `Thermostat` | `setMode(String mode)` (e.g. `"eco"`, `"comfort"`) |
| `DoorLock` | `lock()`, `unlock()` → notifies hub with event `"locked"` / `"unlocked"` |

Each device has a `name` and a reference to the hub (or receives it via method, per your language's constraints).

### Mediator — `SmartHomeHub`

- `register(Device device)` — add a device
- `notify(Device sender, String event)` — the coordination brain. Rules:
  - On `"motion"` → turn **on** all lights and set the thermostat to `"comfort"`
  - On `"locked"` → **dim** all lights to 10% and set the thermostat to `"eco"`
  - On `"unlocked"` → turn **on** all lights

The hub looks up the relevant devices it manages and drives them. Devices never call each other.

### What to implement

1. A `Device` abstraction (interface/trait/base) + the 4 concrete devices
2. `SmartHomeHub` mediator holding references to the devices it controls
3. `Main`:
   - Register a motion sensor, two lights, a thermostat, and a door lock
   - Trigger `motionSensor.detectMotion()` → lights on, thermostat comfort
   - Trigger `doorLock.lock()` → lights dim to 10%, thermostat eco
   - Trigger `doorLock.unlock()` → lights on

### Expected Result (shape)

```
[MotionSensor] motion detected
  Hub: turning on all lights, thermostat -> comfort
    Living Room Light ON
    Kitchen Light ON
    Thermostat mode: comfort
[DoorLock] locked
  Hub: dimming lights to 10%, thermostat -> eco
    Living Room Light dimmed to 10%
    Kitchen Light dimmed to 10%
    Thermostat mode: eco
[DoorLock] unlocked
  Hub: turning on all lights
    Living Room Light ON
    Kitchen Light ON
```

## Constraints

- One file per class/type in all 4 languages
- Devices depend **only** on the hub, never on each other
- All cross-device rules live in `SmartHomeHub.notify(...)`
- Adding a new device or rule must not require editing existing devices
- Keep the hub focused — if it starts to sprawl, note where you'd split it (avoid the god-object trap)

## Design Question to Answer (in a comment)

This looks a lot like **Observer** (devices notify, others react). Explain in 2–3 sentences **why it's Mediator, not Observer** here. (Hint: the hub coordinates *bi-directional, rule-based* interactions between peers, not a one-way state broadcast.)

## Stretch Goal (optional)

Model each hub action (turn on, dim, set mode) as a **Command** object (Ch18) so the hub builds and runs a list of commands per event — and could log or undo them.

## Submission

Put your solution in `20-Mediator/assignments/medium/src/{java,cpp,rust,go}/`.
