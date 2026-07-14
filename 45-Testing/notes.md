# Chapter 45 — Testing & Testable Design

> **Phase 6 — Advanced Topics.** Concept-driven, in Java and C++. The punchline: **testable design and good design are the same thing.** Code that's hard to test is almost always hard to change — the tests are just the first client to complain.

## What & Why

A **unit test** verifies one small piece of behavior in isolation, automatically and fast. But you can only test a unit *in isolation* if its dependencies can be **swapped out** — which forces you to depend on **abstractions**, inject collaborators, and keep classes focused. So "make it testable" pushes you straight toward SOLID.

This chapter is about **designing for testability** (the real skill) more than test syntax. We'll use a tiny hand-rolled assert harness so the examples run anywhere; in practice you'd use **JUnit 5** (Java) or **GoogleTest/Catch2** (C++), and **Mockito** for mocks.

---

## 1. Anatomy of a Unit Test: Arrange–Act–Assert

Every good test has three phases:

```java
@Test
void vipGetsTwentyPercentOff() {
    // Arrange — set up the object and inputs
    DiscountStrategy vip = new VipDiscount();
    // Act — invoke the one behavior under test
    double result = vip.discount(200);
    // Assert — verify the outcome
    assertEquals(40.0, result);
}
```

One test, one behavior, one reason to fail. If a test can fail for two reasons, split it.

---

## 2. What Makes Code *Un*testable

These "hidden dependencies" make a class impossible to test in isolation — and they're the same things that make it hard to change:

| Anti-pattern | Why it kills testability |
|--------------|--------------------------|
| `new Dependency()` **inside** a method | You can't substitute a fake — you're stuck with the real (slow/networked) thing |
| **Singletons / global state** | Tests leak into each other; you can't reset or swap the instance |
| **`static` calls** to collaborators | No seam to intercept; can't verify or stub |
| Reading **`System.currentTimeMillis()` / `now()`** directly | Non-deterministic — the test result depends on the wall clock |
| **`Math.random()` / `rand()`** inline | Non-deterministic — can't reproduce a failure |
| Direct **file / network / DB** access | Slow, flaky, needs real infrastructure |

**The cure for all of them is the same: depend on an abstraction and inject it.**

---

## 3. Dependency Injection — the key enabler

**Before (untestable):** the service builds its own gateway and reads the real clock.
```java
class OrderService {
    private final PaymentGateway gateway = new StripeGateway();     // hard-wired!
    double checkout(Order o) {
        long ts = System.currentTimeMillis();                       // non-deterministic!
        gateway.charge(o.total());                                  // hits the network in a test
        return o.total();
    }
}
```

**After (testable):** collaborators are **injected** through the constructor.
```java
class OrderService {
    private final PaymentGateway gateway;
    private final Clock clock;
    OrderService(PaymentGateway gateway, Clock clock) {   // inject the seams
        this.gateway = gateway;
        this.clock = clock;
    }
    double checkout(Order o) {
        long ts = clock.now();
        gateway.charge(o.total());
        return o.total();
    }
}
```

Now a test passes a **fake** gateway and a **fixed** clock — deterministic, fast, offline. This is the **Dependency Inversion Principle** (Ch03) doing double duty: flexible design *and* testable design.

**C++** is identical in spirit — inject an abstract base by reference / `unique_ptr`:
```cpp
class OrderService {
    PaymentGateway& gateway_;
    Clock& clock_;
public:
    OrderService(PaymentGateway& g, Clock& c) : gateway_(g), clock_(c) {}
};
```

---

## 4. Test Doubles (the taxonomy)

"Test double" is the umbrella term (like a stunt double) for anything you substitute for a real collaborator. There are five, from dumbest to smartest:

| Double | What it does | Use when |
|--------|--------------|----------|
| **Dummy** | Passed but never used (fills a parameter) | You must supply an arg that's irrelevant to the test |
| **Stub** | Returns canned answers | You need the collaborator to *return* something (`charge()` → `true`) |
| **Fake** | A working but simplified impl | e.g., an in-memory repository instead of a DB |
| **Spy** | A stub that **also records** how it was called | You want to *verify* interactions afterward |
| **Mock** | Pre-programmed with **expectations**, fails if they're not met | You want to assert "this was called once with X" |

> Stubs answer *"what does it return?"* (state). Mocks/spies answer *"was it called correctly?"* (interaction). Most bugs are caught by **state** assertions; reach for interaction verification only when the *call itself* is the behavior (e.g., "we must charge the card exactly once").

---

## 5. Mocking (Mockito, conceptually)

Mockito generates a double at runtime so you don't hand-write it:
```java
PaymentGateway gateway = mock(PaymentGateway.class);
when(gateway.charge(anyDouble())).thenReturn(true);     // stub a return
// ... act ...
verify(gateway, times(1)).charge(100.0);                // verify the interaction
```
`when/thenReturn` = stubbing (state); `verify` = interaction checking. Our runnable examples hand-roll a **spy** to show exactly what Mockito automates.

---

## 6. Testing a Strategy

Strategies are the *easiest* things to test — they're pure, injected, and side-effect-free.
```java
assertEquals(0.0,  new RegularDiscount().discount(200));
assertEquals(20.0, new PremiumDiscount().discount(200));
assertEquals(40.0, new VipDiscount().discount(200));
```
And to test the *context*, inject a trivial fake strategy so the test doesn't depend on any real pricing:
```java
DiscountStrategy fixedTen = s -> 10.0;       // a stub strategy
double total = processor.process(order, fixedTen);   // assert against a known discount
```
This is why the Strategy pattern (Ch22) is so test-friendly: the algorithm is a parameter.

---

## 7. Testing Observer interactions

To test that a subject **notifies** its observers, register a **spy** observer and check what it received:
```java
class SpyObserver implements EventObserver {
    int count = 0;
    String last;
    public void onEvent(String e) { count++; last = e; }   // records instead of acting
}

SpyObserver spy = new SpyObserver();
subject.addObserver(spy);
subject.fire("saved");
assertEquals(1, spy.count);          // it was notified exactly once
assertEquals("saved", spy.last);     // with the right payload
```
The spy turns an interaction ("did it notify?") into a state assertion ("count == 1").

---

## 8. Test Data Builders (Builder for tests)

Tests need objects, and constructing them inline is noisy and fragile. A **Test Data Builder** (or *Object Mother*) gives readable, default-filled test objects — the Builder pattern (Ch07) applied to tests.
```java
Order order = anOrder().withItem("Widget", 100, 2).build();   // defaults for everything else
```
When a constructor gains a field, you fix the **builder** once instead of every test.

---

## 9. Controlling Time & Randomness

Non-determinism is the enemy of a reliable test. Inject the sources:
```java
interface Clock { long now(); }
class FixedClock implements Clock { public long now() { return 1_000; } }   // deterministic

interface RandomSource { int nextInt(int bound); }
class SeededRandom … // reproducible
```
Now "an order placed at time T" is a value you control, and a "random" dice roll is repeatable. (We used seeded dice back in Snake & Ladder for exactly this reason.)

---

## 10. The Test Pyramid & FIRST

**Pyramid:** many fast **unit** tests at the base, fewer **integration** tests in the middle, very few slow **end-to-end** tests at the top. Push logic down where it's cheap to test.

**FIRST** — good unit tests are:
- **F**ast (milliseconds — run them constantly)
- **I**solated (no shared state; order-independent)
- **R**epeatable (deterministic — no clock/random/network)
- **S**elf-validating (pass/fail, no manual inspection)
- **T**imely (written with the code, ideally test-first / TDD)

---

## 11. Best Practices & Pitfalls

1. **Inject dependencies** — never `new` a collaborator you'd want to fake; no hidden singletons/statics.
2. **Test behavior, not implementation** — assert *what* the method produces, not *how*. Over-mocking couples tests to internals and makes refactoring painful.
3. **Prefer state assertions over interaction verification** — use mocks only when the call *is* the behavior.
4. **One reason to fail per test**; name tests for the behavior (`vipGetsTwentyPercentOff`).
5. **Control time and randomness** by injecting `Clock`/`RandomSource`.
6. **Keep tests fast and isolated** (FIRST) so you run them on every change.
7. **Don't test getters/framework code** — test *your* logic.

---

## What's Next

Study `src/java` and `src/cpp`: a runnable mini test-suite (a hand-rolled `assertEquals`) exercising a DI-based `OrderService` with a **fake/spy** `PaymentGateway` and a **fixed** `Clock`, a Strategy test, and an Observer **spy** verifying notifications. The C++ compiles with `g++ -std=c++17` and prints PASS/FAIL per test. Then the exercises: retrofit a hard-to-test class with DI, and write a Test Data Builder. Final chapter: **46 — LLD Interview Strategies**.
