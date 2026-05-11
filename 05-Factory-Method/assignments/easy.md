# Assignment: Easy — Shape Factory

## Objective
Apply the Factory Method pattern to create different shapes (Circle, Rectangle, Triangle) with their area calculations.

## Requirements

1. **Product interface:** `Shape` with methods `draw()` and `area()`
2. **Concrete Products:** `Circle(radius)`, `Rectangle(width, height)`, `Triangle(base, height)`
3. **Creator (abstract):** `ShapeFactory` with factory method `createShape()` and business method `printShapeInfo()`
4. **Concrete Creators:** `CircleFactory`, `RectangleFactory`, `TriangleFactory`
5. **Main:** Create all three, call `printShapeInfo()` on each

## Expected Output
```
=== Circle ===
Drawing a Circle
Area: 78.54

=== Rectangle ===
Drawing a Rectangle
Area: 24.00

=== Triangle ===
Drawing a Triangle
Area: 15.00
```

## Compile & Run
```
cd 05-Factory-Method/assignments/easy/src
javac chapter05/easy/*.java
java chapter05.easy.Main
```

## Checklist
- [ ] `Shape` is an interface with `draw()` and `area()`
- [ ] Each shape calculates its own area (Tell, Don't Ask)
- [ ] `ShapeFactory` is abstract with factory method `createShape()`
- [ ] `printShapeInfo()` uses `createShape()` — never calls `new` directly
- [ ] Adding a new shape = 2 new files (product + creator), 0 edits to existing code
