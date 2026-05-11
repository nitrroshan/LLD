# Assignment: Messaging System (Easy)

## Objective

Apply the Bridge pattern to separate **message types** from **delivery channels**.

## Requirements

Two independent dimensions:

**Abstraction — Message types:**
- `TextMessage` — plain text, just sends the body
- `UrgentMessage` — wraps body with "URGENT: " prefix and "!!!" suffix

**Implementation — Delivery channels:**
- `EmailSender` — prints: `[Email] To: {recipient} | {body}`
- `SmsSender` — prints: `[SMS] To: {recipient} | {body}` (truncates body to 160 chars)

### Interface

```java
// Implementation
interface MessageSender {
    void sendMessage(String recipient, String body);
    String getChannelName();
}

// Abstraction
abstract class Message {
    protected MessageSender sender;    // ← bridge
    Message(MessageSender sender) { this.sender = sender; }
    abstract void send(String recipient, String body);
}
```

### What to implement

1. **`MessageSender`** — implementation interface
2. **`EmailSender`**, **`SmsSender`** — concrete implementations
3. **`Message`** — abstraction holding the bridge
4. **`TextMessage`** — sends body as-is through the sender
5. **`UrgentMessage`** — wraps body with urgency markers, then sends through the sender
6. **`Main`** — demonstrate all 4 combinations:
   - TextMessage + Email
   - TextMessage + SMS
   - UrgentMessage + Email
   - UrgentMessage + SMS

### Expected Output

```
--- Text + Email ---
[Email] To: alice@example.com | Meeting at 3pm

--- Text + SMS ---
[SMS] To: +1234567890 | Meeting at 3pm

--- Urgent + Email ---
[Email] To: alice@example.com | URGENT: Server is down!!!

--- Urgent + SMS ---
[SMS] To: +1234567890 | URGENT: Server is down!!!
```

## Key Learning

Without Bridge you'd need 4 classes: `TextEmail`, `TextSms`, `UrgentEmail`, `UrgentSms`.
With Bridge: 2 message types + 2 senders = **4 classes total**, and adding a third channel (e.g., push notification) adds just **1 class** instead of 2.

## Submission

Put your solution in `11-Bridge/assignments/easy/src/{java,cpp,rust,go}/`.
