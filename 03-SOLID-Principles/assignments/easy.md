# Assignment: Easy — Refactor a SOLID-Violating Codebase

## Objective
Given a codebase that violates **all 5 SOLID principles**, identify each violation and refactor.

## The Violating Code

The file `assignments/easy/src/chapter03/easy/NotificationSystem.java` contains a single class `NotificationSystem` that:

1. **SRP violation** — Sends notifications AND logs AND formats messages
2. **OCP violation** — Uses `if/else` to choose notification type
3. **LSP violation** — Has a `PushNotification` that throws `UnsupportedOperationException` for scheduling
4. **ISP violation** — All notifiers must implement `schedule()` even if they can't
5. **DIP violation** — Hardcodes `new FileLogger()` inside the class

## Your Task

Refactor into properly separated classes/interfaces. The skeleton files are provided — fill them in.

## Expected Behavior After Refactoring
```
Sending Email to alice@test.com: Your order shipped!
[LOG] Notification sent: Email to alice@test.com
Sending SMS to +1234567890: Your package arrived!
[LOG] Notification sent: SMS to +1234567890
Scheduling Email to bob@test.com at 2024-01-01 09:00
```

## Checklist
- [ ] Each class has one responsibility (SRP)
- [ ] New notification types can be added without modifying existing code (OCP)
- [ ] No `UnsupportedOperationException` anywhere (LSP, ISP)
- [ ] Scheduling is a separate interface (ISP)
- [ ] Logger is injected, not hardcoded (DIP)
- [ ] Code compiles and runs
