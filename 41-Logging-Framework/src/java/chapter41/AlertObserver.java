package chapter41;

/**
 * Observer — fires an alert whenever an ERROR is logged.
 */
public class AlertObserver implements LogObserver {
    @Override
    public void onLog(LogRecord record) {
        if (record.level() == LogLevel.ERROR) {
            System.out.println("  *** ALERT: " + record.message() + " ***");
        }
    }
}
