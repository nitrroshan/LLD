# Assignment: Medium — Cross-Platform Notification System

## Objective
Build a notification system using Abstract Factory combined with Factory Method (Ch05). The system supports **Android** and **iOS** platforms, each producing a family of matching notification components: a push notification, a sound alert, and a vibration pattern.

## Requirements

### Product Interfaces

1. **`PushNotification`**
   - `void send(String message)` — displays the notification
   - `void dismiss()` — dismisses the notification

2. **`SoundAlert`**
   - `void play()` — plays the platform-specific alert sound
   - `void mute()` — silences the alert

3. **`VibrationPattern`**
   - `void vibrate()` — triggers the platform-specific vibration
   - `void stop()` — stops vibration

### Concrete Products

**Android family:**
- `AndroidPushNotification` — shows notification in Android's notification shade
- `AndroidSoundAlert` — plays Android's default notification chime
- `AndroidVibrationPattern` — short-long-short vibration pattern

**iOS family:**
- `IOSPushNotification` — shows notification as iOS banner
- `IOSSoundAlert` — plays iOS tri-tone sound
- `IOSVibrationPattern` — Taptic Engine haptic feedback

### Factory

- **`NotificationFactory`** (abstract/interface) — `createPush()`, `createSound()`, `createVibration()`
- **`AndroidNotificationFactory`** — creates all Android components
- **`IOSNotificationFactory`** — creates all iOS components

### Client

- `notifyUser(NotificationFactory factory, String message)` — creates all three components, sends the push, plays the sound, and triggers vibration. Then dismisses/mutes/stops everything.

## Expected Output
```
=== Android Notification ===
--- Alerting User ---
[Android Push] Notification shade: "You have a new message"
[Android Sound] Playing default notification chime.
[Android Vibration] Buzz-BUZZ-buzz pattern.
--- Clearing ---
[Android Push] Swiped away from notification shade.
[Android Sound] Muted.
[Android Vibration] Stopped.

=== iOS Notification ===
--- Alerting User ---
[iOS Push] Banner: "You have a new message"
[iOS Sound] Playing tri-tone alert.
[iOS Vibration] Taptic Engine haptic tap.
--- Clearing ---
[iOS Push] Banner dismissed.
[iOS Sound] Muted.
[iOS Vibration] Stopped.
```

## Compile & Run (Java)
```
cd 06-Abstract-Factory/assignments/medium/src/java
javac chapter06/medium/*.java
java chapter06.medium.Main
```

## Checklist
- [ ] Three product interfaces: `PushNotification`, `SoundAlert`, `VibrationPattern`
- [ ] Each platform family has matching implementations (all Android or all iOS)
- [ ] `NotificationFactory` has one factory method per product type (this IS Abstract Factory, not just Factory Method)
- [ ] Client method works entirely through interfaces — never mentions Android/iOS classes
- [ ] No `if/else` or `switch` on platform type anywhere
- [ ] Adding a new platform (e.g., "Windows Phone") = 1 factory + 3 products, 0 edits to existing code
- [ ] Each concrete factory uses Factory Method internally (connection to Ch05)
