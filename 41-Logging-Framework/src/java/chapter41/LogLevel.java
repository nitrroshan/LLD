package chapter41;

/**
 * Log levels in ascending severity. A handler writes a record when the record's
 * severity is at or above the handler's threshold.
 */
public enum LogLevel {
    DEBUG(1),
    INFO(2),
    WARN(3),
    ERROR(4);

    private final int severity;

    LogLevel(int severity) {
        this.severity = severity;
    }

    public int severity() {
        return severity;
    }
}
