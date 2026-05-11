# Chapter 04 — Design Principles Beyond SOLID

## What & Why

SOLID gives you 5 powerful rules, but there are other equally important principles that guide day-to-day design decisions. These principles help you avoid common traps like duplicated logic, over-engineering, and tightly coupled code.

**Real-world analogy:** SOLID is like the structural building code (load-bearing walls, exits). These principles are like the craftsmanship guidelines — use the right tool, don't over-decorate, keep the plumbing simple.

---

## 1. DRY — Don't Repeat Yourself

> **Every piece of knowledge must have a single, unambiguous representation in the system.**

If the same logic exists in 2+ places, a change requires updating all of them — and you WILL miss one.

### Bad Example

```java
class OrderService {
    double calculateTotal(List<Item> items) {
        double total = 0;
        for (Item item : items) {
            total += item.price * item.quantity;
            if (item.quantity > 10) total -= item.price * item.quantity * 0.1;
        }
        return total;
    }
}

class InvoiceService {
    double calculateTotal(List<Item> items) {
        double total = 0;
        for (Item item : items) {
            total += item.price * item.quantity;
            if (item.quantity > 10) total -= item.price * item.quantity * 0.1; // same logic, copied!
        }
        return total;
    }
}
```

### Good Example

```java
class PricingCalculator {
    static double calculateTotal(List<Item> items) {
        double total = 0;
        for (Item item : items) {
            total += item.price * item.quantity;
            if (item.quantity > 10) total -= item.price * item.quantity * 0.1;
        }
        return total;
    }
}

class OrderService {
    double getTotal(List<Item> items) { return PricingCalculator.calculateTotal(items); }
}

class InvoiceService {
    double getTotal(List<Item> items) { return PricingCalculator.calculateTotal(items); }
}
```

### DRY is NOT just about code duplication
- **Logic duplication** — same algorithm in two places (even with different variable names)
- **Knowledge duplication** — same business rule encoded in multiple places
- **NOT about removing all similar-looking code** — two methods can look alike but represent different concepts. Don't merge them prematurely.

---

## 2. KISS — Keep It Simple, Stupid

> **The simplest solution that works is the best solution.**

Don't add complexity until you actually need it. Simple code is easier to read, test, debug, and extend.

### Bad Example

```java
// BAD: Over-engineered — AbstractStrategyFactoryBuilder for a simple validation
interface ValidationStrategy { boolean validate(String input); }
abstract class AbstractValidator implements ValidationStrategy { /* ... */ }
class EmailValidatorFactory {
    AbstractValidator create() { return new ConcreteEmailValidator(); }
}
// ... 5 more classes for ONE validation check
```

### Good Example

```java
// GOOD: Just a method — no pattern needed for something this simple
class Validator {
    static boolean isValidEmail(String email) {
        return email != null && email.contains("@");
    }
}
```

### When complexity is justified
- When you genuinely need multiple strategies at runtime
- When the code is a known extension point (not a hypothetical one)
- When the simpler version has already caused problems

---

## 3. YAGNI — You Aren't Gonna Need It

> **Don't implement something until you actually need it.**

Developers love anticipating future requirements. Resist the urge. Build for today's requirements. Tomorrow's requirements might never come, or they'll be different from what you predicted.

### Bad Example

```java
// BAD: "What if we need to support XML and YAML someday?"
interface DataExporter {
    void exportToJson(Data data);
    void exportToXml(Data data);    // nobody asked for this
    void exportToYaml(Data data);   // nobody asked for this
    void exportToCsv(Data data);    // nobody asked for this
}
```

### Good Example

```java
// GOOD: Only what's needed NOW
interface DataExporter {
    void export(Data data);
}

class JsonExporter implements DataExporter {
    public void export(Data data) { /* JSON export */ }
}
// When XML is actually needed, add XmlExporter then — not before
```

### YAGNI + OCP work together
Design your code so it's EASY to extend (OCP), but don't actually extend it until needed (YAGNI). Create the interface, but only add concrete implementations when there's a real requirement.

---

## 4. Composition Over Inheritance

> **Favor composing objects (has-a) over inheriting from a class (is-a).**

This is one of the most important principles in LLD. Inheritance creates tight coupling, rigid hierarchies, and breaks encapsulation. Composition is flexible, testable, and loosely coupled.

### Bad Example — Inheritance Abuse

```java
// BAD: Deep inheritance hierarchy for feature combinations
class Animal { void eat() { } }
class FlyingAnimal extends Animal { void fly() { } }
class SwimmingAnimal extends Animal { void swim() { } }
class FlyingSwimmingAnimal extends FlyingAnimal { void swim() { } } // awkward!
// What about a swimming-but-not-flying animal? Hierarchy breaks.
```

**Problem:** Feature combinations grow exponentially. Java's single inheritance means you can't mix-and-match.

### Good Example — Composition

```java
// GOOD: Compose behaviors via interfaces and delegation
interface Eater { void eat(); }
interface Flyer { void fly(); }
interface Swimmer { void swim(); }

class DefaultEater implements Eater {
    public void eat() { System.out.println("Eating..."); }
}

class WingFlyer implements Flyer {
    public void fly() { System.out.println("Flying with wings!"); }
}

class FinSwimmer implements Swimmer {
    public void swim() { System.out.println("Swimming with fins!"); }
}

// Duck: eats, flies, AND swims — composed, not inherited
class Duck implements Eater, Flyer, Swimmer {
    private Eater eater = new DefaultEater();
    private Flyer flyer = new WingFlyer();
    private Swimmer swimmer = new FinSwimmer();

    public void eat() { eater.eat(); }
    public void fly() { flyer.fly(); }
    public void swim() { swimmer.swim(); }
}

// Penguin: eats and swims, but NOT fly
class Penguin implements Eater, Swimmer {
    private Eater eater = new DefaultEater();
    private Swimmer swimmer = new FinSwimmer();

    public void eat() { eater.eat(); }
    public void swim() { swimmer.swim(); }
}
```

### When to use Inheritance
- True **is-a** relationship (a Dog IS-A Animal)
- Shallow hierarchies (max 2-3 levels)
- The parent is abstract and stable (won't change often)

### When to use Composition
- **has-a** or **can-do** relationships
- Behavior needs to be mixed-and-matched
- You need flexibility to swap implementations at runtime

---

## 5. Law of Demeter (Principle of Least Knowledge)

> **An object should only talk to its immediate friends, not strangers.**

Don't chain method calls through objects to reach deep into another object's internals. Each object should only call methods on:
1. Itself
2. Its fields
3. Parameters passed to the method
4. Objects it creates

### Bad Example — Train Wreck

```java
// BAD: Reaching through 3 levels of objects
String city = order.getCustomer().getAddress().getCity();
// order knows about Customer, Customer's Address, AND Address's city
```

### Good Example

```java
// GOOD: Tell, don't ask — delegate to the immediate friend
String city = order.getShippingCity();

// Inside Order:
class Order {
    private Customer customer;
    String getShippingCity() { return customer.getCity(); }
}

// Inside Customer:
class Customer {
    private Address address;
    String getCity() { return address.getCity(); }
}
```

### Why it matters
- Reduces coupling — Order doesn't need to know Address exists
- If Address structure changes, only Customer needs updating, not every caller

---

## 6. Tell, Don't Ask

> **Tell objects what to do, don't ask for their data and decide for them.**

Instead of getting an object's state and making decisions outside, push the decision INTO the object.

### Bad Example

```java
// BAD: Ask for data, decide externally
if (account.getBalance() > amount) {
    account.setBalance(account.getBalance() - amount);
}
```

### Good Example

```java
// GOOD: Tell the object what to do
account.withdraw(amount);  // Account decides if it's valid internally
```

### Connection to Encapsulation
"Tell, Don't Ask" is encapsulation in action. The object owns its data AND the behavior on that data. Outsiders tell it what to do; they don't reach in and modify state directly.

---

## Principle Summary

| Principle | One-liner | Violation smell |
|-----------|-----------|----------------|
| DRY | One source of truth | Same logic in 2+ places |
| KISS | Simplest working solution | Patterns for problems that don't exist |
| YAGNI | Build only what's needed now | Unused interfaces, dead code |
| Composition > Inheritance | Has-a over is-a | Deep hierarchies, rigid coupling |
| Law of Demeter | Talk to friends only | Method chains (`a.b().c().d()`) |
| Tell, Don't Ask | Push decisions into objects | Getters followed by external logic |

---

## How These Connect to SOLID

| Principle | SOLID relationship |
|-----------|-------------------|
| DRY | Complements SRP — extracted code gets its own class |
| KISS | Guards against over-applying OCP/DIP |
| YAGNI | Guards against premature OCP |
| Composition > Inheritance | Enables DIP, OCP |
| Law of Demeter | Complements SRP, DIP |
| Tell, Don't Ask | Complements encapsulation (OOP) |

---

## What's Next

Study the code examples in `src/` — a complete before/after refactoring from inheritance to composition. Then tackle the assignments.
