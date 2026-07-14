package chapter41;

/**
 * Plain-text formatter: [t=..][LEVEL] message.
 */
public class SimpleFormatter implements Formatter {
    @Override
    public String format(LogRecord record) {
        return "[t=" + record.timestamp() + "][" + record.level() + "] " + record.message();
    }
}
