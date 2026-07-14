package chapter41;

/**
 * Strategy — a destination for formatted log lines.
 */
public interface Appender {
    void append(String line);
}
