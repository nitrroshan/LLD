package chapter41;

/**
 * Chain of Responsibility — a handler with a severity threshold, a formatter,
 * and an appender. A record flows through the chain; each handler writes it
 * (via its appender) when the record's severity meets the threshold, then
 * forwards to the next handler regardless.
 */
public class LogHandler {
    private final LogLevel threshold;
    private final Formatter formatter;
    private final Appender appender;
    private LogHandler next;

    public LogHandler(LogLevel threshold, Formatter formatter, Appender appender) {
        this.threshold = threshold;
        this.formatter = formatter;
        this.appender = appender;
    }

    /** Wire the next handler; returns it for fluent chaining. */
    public LogHandler setNext(LogHandler next) {
        this.next = next;
        return next;
    }

    public void handle(LogRecord record) {
        if (record.level().severity() >= threshold.severity()) {
            appender.append(formatter.format(record));
        }
        if (next != null) {
            next.handle(record);
        }
    }
}
