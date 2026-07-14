package chapter41;

import java.util.EnumMap;
import java.util.Map;

/**
 * Observer — counts records by level (a stand-in for a metrics dashboard).
 */
public class LogCountObserver implements LogObserver {
    private final Map<LogLevel, Integer> counts = new EnumMap<>(LogLevel.class);

    @Override
    public void onLog(LogRecord record) {
        counts.merge(record.level(), 1, Integer::sum);
    }

    public void printSummary() {
        System.out.print("  Log counts:");
        for (LogLevel level : LogLevel.values()) {
            System.out.print(" " + level + "=" + counts.getOrDefault(level, 0));
        }
        System.out.println();
    }
}
