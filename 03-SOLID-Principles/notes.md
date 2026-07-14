# Chapter 03 — SOLID Principles

## What & Why

SOLID is a set of 5 design principles that make software **easier to maintain, extend, and test**. They're the bridge between raw OOP and design patterns — almost every pattern you'll learn later is a specific application of one or more SOLID principles.

**Real-world analogy:** Think of SOLID as building codes for construction. You *can* build a house without following codes, but it'll be fragile, hard to renovate, and dangerous. SOLID principles are the building codes of software.

---

## S — Single Responsibility Principle (SRP)

> **A class should have only one reason to change.**

Every class should do ONE thing and do it well. If a class has multiple responsibilities, changes to one responsibility can break the other.

### Bad Example

```java
// BAD: Employee does too many things — data, persistence, AND formatting
class Employee {
    private String name;
    private double salary;

    void saveToDatabase() { /* SQL logic here */ }
    String generatePaySlip() { /* formatting logic */ }
    double calculateTax() { /* tax rules */ }
}
```

If the database changes, you edit Employee. If tax rules change, you edit Employee. If the pay slip format changes, you edit Employee. **Three reasons to change = SRP violation.**

### Good Example

```java
// GOOD: Each class has ONE responsibility
class Employee {
    private String name;
    private double salary;
    // Only holds employee data
}

class EmployeeRepository {
    void save(Employee emp) { /* database logic */ }
}

class PaySlipGenerator {
    String generate(Employee emp) { /* formatting logic */ }
}

class TaxCalculator {
    double calculate(Employee emp) { /* tax rules */ }
}
```

Now if tax rules change, only `TaxCalculator` changes. Everything else stays untouched.

**Same split in C++** — data in a `struct`, each responsibility its own class:

```cpp
struct Employee {                 // just holds data (struct = public members)
    std::string name;
    double salary;
};

class EmployeeRepository {
public:
    void save(const Employee& emp) { /* database logic */ }
};

class PaySlipGenerator {
public:
    std::string generate(const Employee& emp) { /* formatting */ return {}; }
};

class TaxCalculator {
public:
    double calculate(const Employee& emp) { /* tax rules */ return 0.0; }
};
```

### How to spot SRP violations
- Class name contains "And" (e.g., `ReaderAndWriter`)
- Class has methods that don't relate to each other
- You can't describe the class in one sentence without using "and"

---

## O — Open/Closed Principle (OCP)

> **Software entities should be open for extension, but closed for modification.**

You should be able to add new behavior **without changing existing code**. Use abstraction (interfaces, abstract classes) so new features are added by creating new classes, not editing old ones.

### Bad Example

```java
// BAD: Adding a new shape requires modifying this method
class AreaCalculator {
    double calculate(Object shape) {
        if (shape instanceof Circle c) {
            return Math.PI * c.radius * c.radius;
        } else if (shape instanceof Rectangle r) {
            return r.width * r.height;
        }
        // Adding Triangle? Must edit this method!
        return 0;
    }
}
```

### Good Example

```java
// GOOD: New shapes are added by creating new classes, not editing existing code
interface Shape {
    double area();
}

class Circle implements Shape {
    double radius;
    public double area() { return Math.PI * radius * radius; }
}

class Rectangle implements Shape {
    double width, height;
    public double area() { return width * height; }
}

// Adding Triangle? Just create a new class — nothing else changes!
class Triangle implements Shape {
    double base, height;
    public double area() { return 0.5 * base * height; }
}

class AreaCalculator {
    double calculate(Shape shape) {
        return shape.area();  // works for ALL shapes, past and future
    }
}
```

**In C++** the extension point is a pure virtual method:

```cpp
class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;      // the extension point
};

class Circle : public Shape {
    double radius;
public:
    explicit Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
};

// Adding Triangle? Just a new class implementing Shape — nothing else changes.
class AreaCalculator {
public:
    double calculate(const Shape& shape) const { return shape.area(); }  // by reference, no slicing
};
```

### Key insight
OCP is achieved through **polymorphism**. The `AreaCalculator` depends on the `Shape` interface, not concrete classes. New shapes "extend" the system by implementing the interface.

---

## L — Liskov Substitution Principle (LSP)

> **Subtypes must be substitutable for their base types.**

If you have a function that takes a `Parent`, passing any `Child` should work correctly without the function needing to know which child it got.

### Bad Example

```java
// BAD: Square violates LSP — it can't behave like a Rectangle
class Rectangle {
    protected int width, height;

    void setWidth(int w) { this.width = w; }
    void setHeight(int h) { this.height = h; }
    int area() { return width * height; }
}

class Square extends Rectangle {
    @Override
    void setWidth(int w) { this.width = w; this.height = w; }  // forced to change both!

    @Override
    void setHeight(int h) { this.width = h; this.height = h; }
}

// This test PASSES for Rectangle but FAILS for Square:
void testArea(Rectangle r) {
    r.setWidth(5);
    r.setHeight(4);
    assert r.area() == 20;  // Square: 4*4=16, FAIL!
}
```

The Square **can't substitute** for Rectangle without breaking expectations. This violates LSP.

### Good Example

```java
// GOOD: Both are independent implementations of a common interface
interface Shape {
    int area();
}

class Rectangle implements Shape {
    private int width, height;
    Rectangle(int w, int h) { this.width = w; this.height = h; }
    public int area() { return width * height; }
}

class Square implements Shape {
    private int side;
    Square(int s) { this.side = s; }
    public int area() { return side * side; }
}
```

**C++** — same fix, two independent implementations of a common base:

```cpp
class Shape {
public:
    virtual ~Shape() = default;
    virtual int area() const = 0;
};

class Rectangle : public Shape {
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int area() const override { return width * height; }
};

class Square : public Shape {
    int side;
public:
    explicit Square(int s) : side(s) {}
    int area() const override { return side * side; }
};
```

### How to spot LSP violations
- Overridden method throws an unexpected exception
- Overridden method does nothing (empty body)
- Child class needs special `instanceof` checks in calling code
- "A square IS-A rectangle" seems logical but breaks behavior

---

## I — Interface Segregation Principle (ISP)

> **No client should be forced to depend on methods it doesn't use.**

Don't create fat interfaces. Split them into smaller, focused ones so implementors only need to implement what's relevant.

### Bad Example

```java
// BAD: Fat interface forces ALL workers to implement every method
interface Worker {
    void work();
    void eat();
    void sleep();
    void attendMeeting();
}

// Robot can't eat or sleep!
class Robot implements Worker {
    public void work() { /* works */ }
    public void eat() { /* ???  */ }        // forced to implement
    public void sleep() { /* ??? */ }       // forced to implement
    public void attendMeeting() { /* ??? */ }
}
```

### Good Example

```java
// GOOD: Segregated interfaces — implement only what you need
interface Workable {
    void work();
}

interface Feedable {
    void eat();
    void sleep();
}

interface Collaboratable {
    void attendMeeting();
}

class HumanWorker implements Workable, Feedable, Collaboratable {
    public void work() { /* works */ }
    public void eat() { /* eats */ }
    public void sleep() { /* sleeps */ }
    public void attendMeeting() { /* attends */ }
}

class Robot implements Workable {
    public void work() { /* works */ }
    // No need to implement eat, sleep, or attendMeeting!
}
```

**C++** — small pure-virtual bases; a class inherits only the ones it needs:

```cpp
class Workable {
public:
    virtual ~Workable() = default;
    virtual void work() = 0;
};

class Feedable {
public:
    virtual ~Feedable() = default;
    virtual void eat() = 0;
    virtual void sleep() = 0;
};

class Collaboratable {
public:
    virtual ~Collaboratable() = default;
    virtual void attend_meeting() = 0;
};

class HumanWorker : public Workable, public Feedable, public Collaboratable {
public:
    void work() override {}
    void eat() override {}
    void sleep() override {}
    void attend_meeting() override {}
};

class Robot : public Workable {    // implements ONLY what it needs
public:
    void work() override {}
};
```

### Rule of thumb
If you see empty method implementations or `UnsupportedOperationException` in a class, you probably have a fat interface that needs splitting.

---

## D — Dependency Inversion Principle (DIP)

> **High-level modules should not depend on low-level modules. Both should depend on abstractions.**

Don't hardcode dependencies on concrete classes. Depend on interfaces instead, and inject the implementation.

### Bad Example

```java
// BAD: NotificationService is tightly coupled to EmailSender
class EmailSender {
    void send(String message) { System.out.println("Email: " + message); }
}

class NotificationService {
    private EmailSender sender = new EmailSender();  // hardcoded dependency!

    void notify(String message) {
        sender.send(message);
    }
    // Want to switch to SMS? Must rewrite NotificationService!
}
```

### Good Example

```java
// GOOD: Depend on abstraction, inject the implementation
interface MessageSender {
    void send(String message);
}

class EmailSender implements MessageSender {
    public void send(String message) { System.out.println("Email: " + message); }
}

class SmsSender implements MessageSender {
    public void send(String message) { System.out.println("SMS: " + message); }
}

class NotificationService {
    private MessageSender sender;  // depends on abstraction!

    NotificationService(MessageSender sender) {  // injected via constructor
        this.sender = sender;
    }

    void notify(String message) {
        sender.send(message);
    }
}

// Usage: easily swap implementations
NotificationService emailNotifier = new NotificationService(new EmailSender());
NotificationService smsNotifier = new NotificationService(new SmsSender());
```

**C++** — the abstraction is a pure-virtual base; inject the implementation:

```cpp
class MessageSender {
public:
    virtual ~MessageSender() = default;
    virtual void send(const std::string& message) = 0;
};

class EmailSender : public MessageSender {
public:
    void send(const std::string& message) override { std::cout << "Email: " << message << "\n"; }
};

class SmsSender : public MessageSender {
public:
    void send(const std::string& message) override { std::cout << "SMS: " << message << "\n"; }
};

class NotificationService {
    MessageSender& sender;                        // depends on the abstraction, not a concrete class
public:
    explicit NotificationService(MessageSender& sender) : sender(sender) {}   // injected
    void notify(const std::string& message) { sender.send(message); }
};

// Usage
EmailSender email;
SmsSender sms;
NotificationService emailNotifier(email);
NotificationService smsNotifier(sms);
```

> Injection choice mirrors ownership (Ch02): a **reference** (shown) when someone else owns the sender, **`std::unique_ptr<MessageSender>`** when the service should own it, or **`std::shared_ptr`** when it's shared.

### Key insight
DIP is about **inverting the direction of dependency**. Instead of high-level code depending on low-level details, both depend on an interface that sits between them.

---

## SOLID Summary

| Principle | One-liner | Violation smell |
|-----------|-----------|----------------|
| **S**RP | One class = one job | Class has unrelated methods |
| **O**CP | Add behavior by adding code, not changing it | `if/else` or `switch` on types |
| **L**SP | Subtypes must behave like their parent | `instanceof` checks, empty overrides |
| **I**SP | Small, focused interfaces | Empty method implementations |
| **D**IP | Depend on abstractions, not concretions | `new ConcreteClass()` inside another class |

---

## How SOLID Connects to Design Patterns

| Pattern | Primary SOLID principle |
|---------|----------------------|
| Strategy | OCP, DIP |
| Factory | OCP, DIP |
| Observer | OCP, DIP |
| Decorator | OCP, SRP |
| Adapter | DIP, ISP |
| Template Method | OCP |
| Command | SRP |

You'll see these connections in later chapters.

---

## Common Pitfalls

1. **Over-applying SRP** — Don't create a class for every single method. Balance is key.
2. **OCP doesn't mean never modify** — It means design so that common extension points don't require modification.
3. **LSP isn't just about compilation** — Code can compile but still violate LSP if behavior is wrong.
4. **ISP vs SRP** — SRP is about classes, ISP is about interfaces. A class can follow SRP but implement a fat interface (ISP violation).
5. **DIP ≠ Dependency Injection** — DIP is the principle (depend on abstractions). DI is one technique to achieve it.

---

## What's Next

Study the code examples in `src/` — each file demonstrates a SOLID principle with a before/after comparison. Then tackle the assignments.
