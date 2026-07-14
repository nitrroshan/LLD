package chapter41;

/**
 * Strategy — turns a record into a line of text.
 */
public interface Formatter {
    String format(LogRecord record);
}
