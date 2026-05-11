# Assignment: Medium — Banking System

## Objective
Practice **all 4 OOP pillars** plus **interfaces** by building a mini banking system.

## Requirements

### Interfaces:

1. **`Transferable`**
   - Method: `boolean transfer(BankAccount destination, double amount)`

2. **`InterestBearing`**
   - Method: `void applyInterest()`

### Classes:

1. **`BankAccount`** (abstract class, implements `Transferable`)
   - Private fields: `accountNumber` (String), `holderName` (String), `balance` (double)
   - Constructor, getters
   - `deposit(double amount)` — concrete, validates amount > 0
   - `withdraw(double amount)` — concrete, validates sufficient balance
   - `abstract String getAccountType()`
   - Implement `transfer()` — withdraw from this, deposit into destination
   - `displayAccount()` — prints account type, number, holder, balance

2. **`SavingsAccount`** extends `BankAccount` implements `InterestBearing`
   - Private field: `interestRate` (double, e.g., 0.04 for 4%)
   - Implement `getAccountType()` → returns "Savings"
   - Implement `applyInterest()` → balance += balance * interestRate
   - Override `withdraw()` → must maintain minimum balance of 500 (if withdrawal would drop below 500, reject it)

3. **`CurrentAccount`** extends `BankAccount`
   - Private field: `overdraftLimit` (double)
   - Implement `getAccountType()` → returns "Current"
   - Override `withdraw()` → allows withdrawal up to (balance + overdraftLimit)

4. **`Main`** class — demonstrate:
   - Create one SavingsAccount and one CurrentAccount
   - Deposit into both
   - Transfer from savings to current
   - Apply interest on savings
   - Try withdrawing beyond limits on both (show error handling)
   - Display both accounts at the end

## Expected Behavior
```
--- Setup ---
Created Savings Account: SA-001 for Alice (Balance: 5000.0)
Created Current Account: CA-001 for Bob (Balance: 2000.0)

--- Deposits ---
Alice deposited 1000.0. New balance: 6000.0
Bob deposited 500.0. New balance: 2500.0

--- Transfer 2000 from Alice to Bob ---
Transfer successful! Alice: 4000.0, Bob: 4500.0

--- Apply Interest (4%) to Savings ---
Interest applied. Alice new balance: 4160.0

--- Withdrawal Tests ---
Alice tries to withdraw 4000.0... REJECTED (minimum balance 500)
Bob tries to withdraw 5500.0 (overdraft limit: 1000)... SUCCESS. Bob balance: -1000.0

--- Final Balances ---
[Savings] SA-001 | Alice | Balance: 4160.0
[Current] CA-001 | Bob   | Balance: -1000.0
```

## OOP Concepts Tested

| Concept | Where |
|---------|-------|
| Encapsulation | Private fields, validation in deposit/withdraw |
| Inheritance | SavingsAccount & CurrentAccount extend BankAccount |
| Polymorphism | Different withdraw behavior per account type |
| Abstraction | BankAccount is abstract; Transferable & InterestBearing are interfaces |
| Interface | Multiple interfaces on SavingsAccount |

## Checklist
- [ ] `BankAccount` is abstract
- [ ] Both interfaces are implemented correctly
- [ ] SavingsAccount enforces minimum balance of 500
- [ ] CurrentAccount supports overdraft
- [ ] Transfer works via the `Transferable` interface
- [ ] `@Override` used everywhere appropriate
- [ ] All fields are private
- [ ] Main demonstrates all scenarios above

## Starter Code

Skeleton files are provided in two languages:

### Java

Files in `assignments/medium/src/chapter01/medium/`:
- `Transferable.java`, `InterestBearing.java`, `BankAccount.java`, `SavingsAccount.java`, `CurrentAccount.java`, `Main.java`

```bash
cd 01-OOP-Refresher/assignments/medium/src
javac chapter01/medium/*.java
java chapter01.medium.Main
```

### C++

Files in `assignments/medium/src/cpp/`:
- `Transferable.h`, `InterestBearing.h`, `BankAccount.h`, `SavingsAccount.h`, `CurrentAccount.h`, `main.cpp`

C++ differences to note:
- **Interfaces** → abstract classes with only pure virtual methods and a virtual destructor
- **Multiple inheritance** is used directly (C++ supports it natively, unlike Java)
- Use `std::string` instead of `String`
- Use references (`BankAccount&`) instead of object parameters
- Protect balance access in derived classes with a `protected` setter or getter

```bash
cd 01-OOP-Refresher/assignments/medium/src/cpp
g++ -std=c++17 -o main main.cpp
./main
```

## Hint
Start by defining the interfaces, then the abstract class, then the concrete classes. Write `Main` last to test everything.
