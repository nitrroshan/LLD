package chapter41;

import java.util.ArrayList;
import java.util.List;

/**
 * Singleton — the global logger. Holds the handler chain (Chain of
 * Responsibility), observers (Observer), and a global minimum level. Built with
 * the Bill Pugh idiom: lazy and thread-safe without synchronization.
 */
public class Logger {
    private LogHandler chain;
    private final List<LogObserver> observers = new ArrayList<>();
    private LogLevel minLevel = LogLevel.DEBUG;
    private long clock = 0;   // deterministic timestamp for the demo

    private Logger() {}

    private static class Holder {
        private static final Logger INSTANCE = new Logger();
    }

    public static Logger getInstance() {
        return Holder.INSTANCE;
    }

    public void setChain(LogHandler chain) { this.chain = chain; }
    public void addObserver(LogObserver observer) { observers.add(observer); }
    public void setMinLevel(LogLevel minLevel) { this.minLevel = minLevel; }

    public void log(LogLevel level, String message) {
        if (level.severity() < minLevel.severity()) {
            return;   // gated out before any work
        }
        LogRecord record = new LogRecord(level, message, ++clock);
        if (chain != null) {
            chain.handle(record);          // Chain of Responsibility
        }
        for (LogObserver observer : observers) {
            observer.onLog(record);        // Observer
        }
    }

    public void debug(String message) { log(LogLevel.DEBUG, message); }
    public void info(String message) { log(LogLevel.INFO, message); }
    public void warn(String message) { log(LogLevel.WARN, message); }
    public void error(String message) { log(LogLevel.ERROR, message); }
}
