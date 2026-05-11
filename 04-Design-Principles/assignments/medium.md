# Assignment: Medium — Redesign a Class Hierarchy Using Composition

## Objective
Refactor an inheritance-based robot system into a composition-based design. Combines Composition > Inheritance with SOLID from Chapter 03.

## The Problem

A robotics company has these robots built with deep inheritance:

```
Robot
├── WalkingRobot
│   ├── WalkingSpeakingRobot
│   └── WalkingLiftingRobot
├── FlyingRobot
│   ├── FlyingSpeakingRobot
│   └── FlyingLiftingRobot
└── SwimmingRobot
    └── SwimmingLiftingRobot
```

**7 classes** for 3 movements × 2 abilities. Adding "Climbing" movement = 3 more classes.
Adding "Scanning" ability = 7 more classes. This is the **class explosion** problem.

## Your Task

Redesign using composition so that:
1. **Movement** is a composable behavior (Walk, Fly, Swim, Climb)
2. **Ability** is a composable behavior (Speak, Lift, Scan)
3. A **Robot** has a name, ONE movement, and a LIST of abilities
4. Behaviors can be swapped at runtime
5. New movements/abilities = new classes, NO changes to Robot

## Skeleton Files Provided

Fill in the TODOs in `assignments/medium/src/chapter04/medium/`.

## Expected Output
```
=== Helper Bot ===
Helper walks.
Helper speaks: Hello, I am Helper!
Helper lifts 50kg.

=== Drone ===
Drone flies!
Drone scans area.

=== Upgrade: Drone gets speaking ability ===
Drone speaks: Scanning complete!

=== Aqua Bot ===
AquaBot swims.
AquaBot lifts 100kg.
AquaBot scans area.
```

## Compile & Run
```
cd 04-Design-Principles/assignments/medium/src
javac chapter04/medium/*.java
java chapter04.medium.Main
```

## Checklist
- [ ] No inheritance hierarchy for robots (composition only)
- [ ] Robot class has no if/else for movement or ability types
- [ ] Adding a new movement = 1 new class, 0 existing changes (OCP)
- [ ] Adding a new ability = 1 new class, 0 existing changes (OCP)
- [ ] Abilities can be added/removed at runtime
- [ ] Code compiles and produces expected output
