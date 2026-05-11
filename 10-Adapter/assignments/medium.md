# Assignment: Notification Service Integration (Medium)

## Objective

Combine the Adapter pattern with earlier concepts (OCP from Ch03, interfaces from Ch01) to integrate multiple third-party notification services behind a unified interface.

## Context

Your application sends notifications via email, SMS, and push. Each channel uses a different third-party provider with a completely different API. You want a single `NotificationService` interface so the rest of your app doesn't care which provider is behind each channel.

## Requirements

### Target Interface

```java
interface NotificationService {
    boolean send(String recipient, String subject, String body);
    String getServiceName();
    boolean isAvailable();
}
```

### Third-Party APIs (Adaptees)

**`SendGridApi`** (Email provider):

| Method | Signature |
|--------|-----------|
| `sendEmail` | `sendEmail(EmailMessage msg) → SendGridResponse` |

```java
class EmailMessage {
    String to, from, subject, htmlBody;
}
class SendGridResponse {
    int code;       // 202 = accepted
    String messageId;
}
```

**`TwilioApi`** (SMS provider):

| Method | Signature |
|--------|-----------|
| `createMessage` | `createMessage(String from, String to, String body) → TwilioMessage` |
| `getAccountStatus` | `getAccountStatus() → String` ("active" or "suspended") |

```java
class TwilioMessage {
    String sid;
    String status;  // "queued", "sent", "failed"
}
```

**`FirebaseApi`** (Push notification provider):

| Method | Signature |
|--------|-----------|
| `pushNotification` | `pushNotification(String deviceToken, Map<String, String> payload) → boolean` |
| `validateToken` | `validateToken(String token) → boolean` |

### What to implement

1. **All 3 adaptee classes** with the exact APIs above (simulate — just print and return success)
2. **`SendGridAdapter`** — adapts email:
   - `send(recipient, subject, body)` → builds `EmailMessage`, calls `sendEmail`, returns code == 202
   - Use a configured `fromAddress` (set in constructor)
3. **`TwilioAdapter`** — adapts SMS:
   - `send(recipient, subject, body)` → ignore subject, calls `createMessage`, returns status != "failed"
   - `isAvailable()` → calls `getAccountStatus()`, returns true if "active"
   - Use a configured `fromNumber` (set in constructor)
4. **`FirebaseAdapter`** — adapts push:
   - `send(recipient, subject, body)` → recipient is device token, builds payload map with "title"=subject and "body"=body
   - `isAvailable()` → calls `validateToken` with a test token
5. **`NotificationManager`** — holds a list of `NotificationService` instances:
   - `sendAll(recipient, subject, body)` → sends via ALL available services
   - `sendVia(serviceName, recipient, subject, body)` → sends via a specific service
6. **`Main`** — demonstrate sending through all three, then through a specific one

### Expected Output

```
=== Notification Service Adapter ===

--- Send to All ---
[SendGrid] Sending email to user@example.com: "Order Confirmed"
  Email sent (202)
[Twilio] SMS to +1234567890: Order Confirmed - Your order #123 has shipped!
  SMS queued (sid: SM_xxx)
[Firebase] Push to device_token_abc: {title=Order Confirmed, body=Your order #123 has shipped!}
  Push sent successfully

--- Send via Specific Service ---
[Twilio] SMS to +0987654321: "Alert" - Server is down!
  SMS queued (sid: SM_xxx)

--- Check Availability ---
SendGrid: available
Twilio: available
Firebase: available
```

## Constraints

- One file per class/type
- Client code (`Main`, `NotificationManager`) must ONLY use `NotificationService`
- Each adapter must handle the translation of parameters AND return types
- `NotificationManager` should be open for extension — adding a 4th service requires zero changes (OCP)

## Design Hints

- The `subject` parameter isn't used by SMS — the adapter decides how to handle this mismatch
- Firebase expects a `Map` payload — the adapter must convert simple strings to the expected format
- Think about what `recipient` means for each channel: email address, phone number, device token

## Submission

Put your solution in `10-Adapter/assignments/medium/src/{java,cpp,rust,go}/`.
