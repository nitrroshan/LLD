package chapter03.easy;

/**
 * THIS IS THE BAD CODE — read it and understand the violations.
 * Then refactor into the skeleton files provided.
 *
 * Violations:
 *   SRP: This class sends, logs, AND formats
 *   OCP: if/else on type to choose channel
 *   LSP: PushNotification.schedule() throws exception
 *   ISP: All notifiers forced to implement schedule()
 *   DIP: Hardcodes new FileLogger()
 */
public class NotificationSystemBad {

    // DIP violation: hardcoded concrete dependency
    // private FileLogger logger = new FileLogger();

    // OCP violation: adding new types requires modifying this method
    void send(String type, String recipient, String message) {
        if (type.equals("email")) {
            System.out.println("Sending Email to " + recipient + ": " + message);
        } else if (type.equals("sms")) {
            System.out.println("Sending SMS to " + recipient + ": " + message);
        } else if (type.equals("push")) {
            System.out.println("Sending Push to " + recipient + ": " + message);
        }
        // SRP violation: logging is mixed in
        System.out.println("[FILE LOG] Notification sent: " + type + " to " + recipient);
    }

    // ISP violation: schedule doesn't make sense for all types
    void schedule(String type, String recipient, String message, String dateTime) {
        if (type.equals("push")) {
            // LSP violation: push can't be scheduled
            throw new UnsupportedOperationException("Push can't be scheduled!");
        }
        System.out.println("Scheduling " + type + " to " + recipient + " at " + dateTime);
    }
}
