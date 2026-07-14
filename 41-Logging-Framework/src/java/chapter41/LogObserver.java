package chapter41;

/**
 * Observer — reacts to every accepted log record, off the write path.
 */
public interface LogObserver {
    void onLog(LogRecord record);
}
