# Chapter 44 — Refactoring & Code Smells

> **Phase 6 — Advanced Topics.** Concept-driven (before → after code), in Java and C++. This is where every pattern and principle from the course pays off: refactoring is the *act* of removing smells, and the patterns are the *destinations*.

## What & Why

**Refactoring** is changing the *internal structure* of code **without changing its external behavior** — to make it easier to understand and cheaper to modify. A **code smell** is a surface symptom that usually points to a deeper design problem.

The workflow: **spot a smell → apply a small, behavior-preserving refactoring → run the tests → repeat.** Tests are the safety net; without them you're not refactoring, you're just rewriting and hoping.

> The whole course converges here. SOLID and the patterns aren't decorations — they're the **targets** you refactor *toward* when a smell appears.

---

## 1. The Smell Catalog (what to look for)

| Smell | Symptom | Usual cure |
|-------|---------|------------|
| **Long Method** | A method you must scroll to read; comments splitting "sections" | **Extract Method** |
| **Large / God Class** | One class does everything; dozens of fields/methods | **Extract Class** (SRP) |
| **Duplicated Code** | Same logic copy-pasted | Extract Method/Class (DRY) |
| **Long Parameter List** | 5+ params; booleans you can't decode | **Introduce Parameter Object** / Builder |
| **Switch/if-else on type** | `if (type == A) … else if (type == B)` repeated | **Replace Conditional with Polymorphism** (Strategy/State) |
| **Feature Envy** | A method uses another object's data more than its own | **Move Method** to that object |
| **Shotgun Surgery** | One change forces edits in many classes | Gather the responsibility into one class |
| **Primitive Obsession** | `String`/`int` everywhere instead of types (money, email) | Introduce a value type |
| **Data Class** | Getters/setters only; logic lives elsewhere | Move behavior in (**Tell, Don't Ask**) |
| **Message Chains** | `a.getB().getC().getD()` | Hide behind a method (Law of Demeter) |

---

## 2. Extract Method (Long Method → small named steps)

A long method mixing several concerns is hard to read and reuse. Break it into **small, named** methods — each name documents a step.

**Before (Java):**
```java
void printReport(List<Order> orders) {
    double total = 0;
    for (Order o : orders) total += o.amount();      // calc
    System.out.println("=== REPORT ===");             // header
    for (Order o : orders) System.out.println(o.id() + ": " + o.amount()); // body
    System.out.println("Total: " + total);            // footer
}
```

**After:**
```java
void printReport(List<Order> orders) {
    printHeader();
    printLines(orders);
    printFooter(total(orders));           // each step named + reusable + testable
}
private double total(List<Order> orders) { … }
private void printHeader() { … }
private void printLines(List<Order> orders) { … }
private void printFooter(double total) { … }
```

Same idea in C++ — pull each block into a small private member function. The win: the top method now reads like a **summary**, and each step is independently testable.

---

## 3. Replace Conditional with Polymorphism (the big one)

A `switch`/`if-else` **on a type code**, repeated in several places, is the #1 smell in LLD. Replace it with **polymorphism** — this *is* the Strategy (Ch22) / State (Ch25) pattern.

**Before (Java) — type-switch smell:**
```java
double discount(CustomerType type, double subtotal) {
    switch (type) {
        case REGULAR: return 0;
        case PREMIUM: return subtotal * 0.10;
        case VIP:     return subtotal * 0.20;
    }
    return 0;   // and this switch is duplicated wherever discounts appear
}
```

**After — Strategy:**
```java
interface DiscountStrategy { double discount(double subtotal); }
class RegularDiscount implements DiscountStrategy { public double discount(double s){ return 0; } }
class PremiumDiscount implements DiscountStrategy { public double discount(double s){ return s*0.10; } }
class VipDiscount     implements DiscountStrategy { public double discount(double s){ return s*0.20; } }
// caller: strategy.discount(subtotal);  — no switch, and a new tier is a new class (OCP)
```

**C++** is the same shape — a pure-virtual `DiscountStrategy` with concrete subclasses, selected via a factory. Adding a `StudentDiscount` is **one new class**, not an edit to every switch.

> Rule of thumb: **the same `switch`-on-type appearing more than once** is the signal to reach for polymorphism.

---

## 4. Extract Class (God Class → focused classes)

A class that validates, prices, taxes, formats, *and* persists has **many reasons to change** (SRP violation). Split each responsibility into its own class.

```
Before:  OrderProcessor  { validate + price + discount + tax + format + save }   // God class

After:   Order              (data + subtotal)
         DiscountStrategy    (pricing rule — Strategy)
         TaxCalculator       (tax)
         ReceiptFormatter    (presentation)
         OrderRepository     (persistence)
         OrderProcessor      (thin orchestrator that wires them)
```

Each class now has **one reason to change**; you can test tax without touching formatting, swap the receipt format without risking the pricing math.

---

## 5. Move Method (fix Feature Envy)

If a method spends its time reaching into **another** object's data, it belongs **on that object**.

**Before:** `ReceiptPrinter.total(order)` loops over `order.getItems()` computing `item.getPrice()*item.getQty()` — envy.
**After:** `order.subtotal()` — the `Order` computes its own total; the printer just asks. This is **Tell, Don't Ask** (Ch04) in action.

---

## 6. Introduce Parameter Object (Long Parameter List)

```java
// Before — what are these booleans?
createUser("Sam", "sam@x.com", true, false, true, 30);

// After — a named, self-documenting object (or a Builder for many optionals)
createUser(new UserSpec("Sam", "sam@x.com").verified().admin().age(30));
```

Fewer params, self-documenting call sites, and related data travels together. For many *optional* params, this is exactly where the **Builder** pattern (Ch07) shines.

---

## 7. The Refactoring Workflow

1. **Have tests** (or write characterization tests that pin current behavior).
2. **One small step at a time** — extract a method, run tests; rename, run tests.
3. **Never refactor and add features in the same commit** — separate "make the change easy" from "make the easy change."
4. **Commit after each green step** so you can always roll back.
5. **Let the smells guide you** — don't refactor for its own sake; refactor the code you're *about to change*.

> "First make the change easy (this may be hard), then make the easy change." — Kent Beck.

---

## 8. When NOT to Refactor

- **No tests + no time** — stabilize with tests first, or don't touch it.
- **Throwaway / spike code** — YAGNI; don't polish what you'll delete.
- **A rewrite is genuinely cheaper** — occasionally true, but usually a trap (you lose hard-won bug fixes).
- **Over-engineering** — refactoring *toward* a pattern you don't need yet is its own smell. Prefer the simplest thing that removes the *current* pain (KISS).

---

## 9. Smell → Cure Map (ties the whole course together)

| Smell | Refactoring | Pattern / Principle |
|-------|-------------|---------------------|
| Switch on type | Replace Conditional with Polymorphism | **Strategy** / **State** |
| God class | Extract Class | **SRP** |
| Feature envy | Move Method | **Tell, Don't Ask** |
| Duplicated code | Extract Method/Class | **DRY** |
| Long parameter list | Introduce Parameter Object | **Builder** |
| Complex object creation scattered | Extract Factory | **Factory** |
| Adding behavior means editing a class | Wrap it | **Decorator** |
| Hard-coded dependency | Inject an abstraction | **DIP** |

Refactoring is how messy code *becomes* a clean pattern-based design — incrementally, safely, test-guarded.

---

## What's Next

Study `src/java` and `src/cpp`: a smelly `OrderProcessorBefore` (God class + long method + switch-on-type + inline formatting) refactored into a clean design (Order, DiscountStrategy, TaxCalculator, ReceiptFormatter, thin OrderProcessor). The demo runs **both** and prints identical totals — proving the refactor preserved behavior. The C++ compiles with `g++ -std=c++17`. Then the exercises: refactor a second smelly class, and add a new customer tier to *both* versions to feel the difference. Next chapter: **45 — Testing & Testable Design**.
