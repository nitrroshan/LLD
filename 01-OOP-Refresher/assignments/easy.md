# Assignment: Easy — Vehicle Hierarchy

## Objective
Practice **inheritance, polymorphism, encapsulation, and abstraction** by modeling a vehicle system.

## Requirements

Design a vehicle hierarchy with the following:

### Classes to create:

1. **`Vehicle`** (abstract class)
   - Private fields: `brand` (String), `speed` (int, in km/h)
   - Constructor that takes brand and speed
   - Getters for both fields
   - Abstract method: `void displayInfo()`
   - Concrete method: `void accelerate(int amount)` — increases speed by the given amount and prints the new speed

2. **`Car`** extends `Vehicle`
   - Additional private field: `numDoors` (int)
   - Constructor that takes brand, speed, and numDoors
   - Implement `displayInfo()` → print brand, speed, numDoors

3. **`Motorcycle`** extends `Vehicle`
   - Additional private field: `hasSidecar` (boolean)
   - Constructor that takes brand, speed, and hasSidecar
   - Implement `displayInfo()` → print brand, speed, and whether it has a sidecar

4. **`ElectricCar`** extends `Car`
   - Additional private field: `batteryCapacity` (int, in kWh)
   - Constructor that takes brand, speed, numDoors, and batteryCapacity
   - Override `displayInfo()` → print everything including battery capacity

5. **`Main`** class
   - Create an array of `Vehicle` containing at least one of each type
   - Loop through and call `displayInfo()` on each (polymorphism!)
   - Call `accelerate(20)` on each and print the updated info

## Expected Output (example)
```
--- Vehicle Info ---
Car: Toyota | Speed: 120 km/h | Doors: 4
Motorcycle: Harley | Speed: 100 km/h | Sidecar: No
ElectricCar: Tesla | Speed: 150 km/h | Doors: 4 | Battery: 85 kWh

--- After Accelerating ---
Toyota accelerated! New speed: 140 km/h
Harley accelerated! New speed: 120 km/h
Tesla accelerated! New speed: 170 km/h
```

## Checklist
- [ ] All fields are `private` (encapsulation)
- [ ] `Vehicle` is abstract with an abstract method
- [ ] Polymorphism is used via a `Vehicle` array
- [ ] `@Override` annotation is on every overridden method
- [ ] Code compiles and runs with a `main` method

## Starter Code

Skeleton files are provided in two languages:

### Java

Files in `assignments/easy/src/chapter01/easy/`:
- `Vehicle.java`, `Car.java`, `Motorcycle.java`, `ElectricCar.java`, `Main.java`

```bash
cd 01-OOP-Refresher/assignments/easy/src
javac chapter01/easy/*.java
java chapter01.easy.Main
```

### C++

Files in `assignments/easy/src/cpp/`:
- `Vehicle.h`, `Car.h`, `Motorcycle.h`, `ElectricCar.h`, `main.cpp`

C++ differences to note:
- Abstract classes use **pure virtual functions** (`= 0`) instead of `abstract` keyword
- Use `std::string` instead of `String`
- Use `std::vector<std::unique_ptr<Vehicle>>` for polymorphic containers
- Mark overridden methods with `override` keyword
- Always provide a `virtual` destructor in base classes

```bash
cd 01-OOP-Refresher/assignments/easy/src/cpp
g++ -std=c++17 -o main main.cpp
./main
```

Good luck! Try to complete it without looking at the `src/` examples.
