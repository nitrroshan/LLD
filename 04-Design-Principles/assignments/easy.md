# Assignment: Easy — Refactor Tightly-Coupled Code

## Objective
Refactor a tightly-coupled notification system that violates DRY, Law of Demeter, and Tell Don't Ask.

## The Bad Code

`NotificationBad.java` has a `sendPromotion()` method that:
1. **DRY violation** — discount calculation is duplicated in two places
2. **Law of Demeter violation** — chains through `customer.getProfile().getPreferences().getChannel()`
3. **Tell, Don't Ask violation** — pulls data out of Customer and makes decisions externally

## Your Task

Refactor into the skeleton files provided. Each file has TODO comments.

## Expected Output
```
Sending Email to alice@test.com: 20% off! Your price: $80.00
Sending SMS to +1234: 10% off! Your price: $90.00
```

## Compile & Run
```
cd 04-Design-Principles/assignments/easy/src
javac chapter04/easy/*.java
java chapter04.easy.Main
```

## Checklist
- [ ] No duplicated discount logic (DRY)
- [ ] No method chains deeper than 1 dot (Demeter)
- [ ] Customer decides its own notification channel (Tell, Don't Ask)
- [ ] Code compiles and produces expected output
