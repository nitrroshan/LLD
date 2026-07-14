package chapter41;

/**
 * An immutable log record: level, message, and a timestamp.
 */
public class LogRecord {
    private final LogLevel level;
    private final String message;
    private final long timestamp;

    public LogRecord(LogLevel level, String message, long timestamp) {
        this.level = level;
        this.message = message;
        this.timestamp = timestamp;
    }

    public LogLevel level() { return level; }
    public String message() { return message; }
    public long timestamp() { return timestamp; }
}
