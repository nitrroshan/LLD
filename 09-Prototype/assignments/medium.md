# Assignment: Game Unit Spawner (Medium)

## Objective

Combine the **Prototype** pattern with a **Registry** (from this chapter) and **Factory Method** (from Chapter 05) to build a game unit spawning system.

## Context

In a strategy game, you need to spawn many units (soldiers, archers, cavalry). Each unit type has a **base template** with stats, but individual units get unique IDs and positions. Creating each unit from scratch (loading sprites, parsing stats) is expensive. Instead, create one prototype per unit type and clone it.

## Requirements

### Entities

**`Unit`** (abstract/interface) — the prototype:

| Field | Type | Clone behavior |
|-------|------|---------------|
| id | String | Generate NEW unique ID (don't copy) |
| name | String | Copy from prototype |
| health | int | Copy from prototype |
| attack | int | Copy from prototype |
| defense | int | Copy from prototype |
| x, y | int | Set to 0,0 (spawn point) |
| abilities | List of Strings | **Deep copy** |

**Concrete units:** `Soldier`, `Archer`, `Cavalry`

| Unit | Health | Attack | Defense | Abilities |
|------|--------|--------|---------|-----------|
| Soldier | 100 | 15 | 20 | ["slash", "block"] |
| Archer | 70 | 25 | 10 | ["shoot", "dodge"] |
| Cavalry | 120 | 20 | 15 | ["charge", "trample", "retreat"] |

**`UnitRegistry`** — stores prototypes by name, returns clones.

**`UnitSpawner`** — uses the registry to spawn units:
- `spawn(unitType, x, y)` → clones from registry, assigns unique ID, sets position
- ID format: `"{type}-{incrementing number}"` (e.g., `"soldier-1"`, `"soldier-2"`, `"archer-1"`)

### What to implement

1. **`Unit`** — abstract class/interface with `clone()`, copy constructor
2. **`Soldier`**, **`Archer`**, **`Cavalry`** — concrete units with their stats
3. **`UnitRegistry`** — maps unit type names to prototype objects
4. **`UnitSpawner`** — factory that uses the registry to spawn positioned, ID'd units
5. **`Main`** — Demonstrate:
   - Register prototypes
   - Spawn 3 soldiers, 2 archers, 1 cavalry at different positions
   - Modify one soldier's abilities (e.g., add "shield_bash") — show others are unaffected
   - Print all spawned units

### Expected Output

```
=== Game Unit Spawner ===

Spawned: soldier-1 [Soldier hp=100 atk=15 def=20 pos=(10,20) abilities=[slash, block]]
Spawned: soldier-2 [Soldier hp=100 atk=15 def=20 pos=(30,40) abilities=[slash, block]]
Spawned: soldier-3 [Soldier hp=100 atk=15 def=20 pos=(50,60) abilities=[slash, block]]
Spawned: archer-1  [Archer hp=70 atk=25 def=10 pos=(100,200) abilities=[shoot, dodge]]
Spawned: archer-2  [Archer hp=70 atk=25 def=10 pos=(120,200) abilities=[shoot, dodge]]
Spawned: cavalry-1 [Cavalry hp=120 atk=20 def=15 pos=(200,100) abilities=[charge, trample, retreat]]

--- Modify soldier-1's abilities ---
soldier-1: [slash, block, shield_bash]
soldier-2: [slash, block]               ← unaffected (deep copy)
soldier-3: [slash, block]               ← unaffected (deep copy)
```

## Constraints

- One file per class/type
- Must deep copy the `abilities` list
- Each clone must get a **new unique ID** (not copied from prototype)
- Use the **Registry** pattern to store and retrieve prototypes
- `UnitSpawner` manages ID generation (incrementing counter per type)

## Design Hints

- `UnitSpawner` composes a `UnitRegistry` — it doesn't extend it
- The unique ID counter can be a `Map<String, Integer>` in the spawner (e.g., `{"soldier": 3, "archer": 2, "cavalry": 1}`)
- This combines **Prototype** (cloning), **Registry** (lookup), and a touch of **Factory** (the spawner creates configured instances)

## Submission

Put your solution in `09-Prototype/assignments/medium/src/{java,cpp,rust,go}/`.
