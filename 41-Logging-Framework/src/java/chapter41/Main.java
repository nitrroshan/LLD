package chapter41;

/**
 * Demo — configures the singleton logger with a console->file->error handler
 * chain routing by severity, observers counting records and alerting on errors,
 * then logs at every level and shows a runtime level change.
 */
public class Main {
    public static void main(String[] args) {
        System.out.println("=== Logging Framework Demo (Java) ===\n");

        Logger log = Logger.getInstance();
        Formatter simple = new SimpleFormatter();

        // Chain of Responsibility: console(DEBUG) -> file(WARN) -> error(ERROR).
        LogHandler console = new LogHandler(LogLevel.DEBUG, simple, new ConsoleAppender());
        console.setNext(new LogHandler(LogLevel.WARN, simple, new FileAppender("app.log")))
               .setNext(new LogHandler(LogLevel.ERROR, simple, new FileAppender("error.log")));
        log.setChain(console);

        // Observers.
        LogCountObserver counter = new LogCountObserver();
        log.addObserver(counter);
        log.addObserver(new AlertObserver());

        // 1) Log at every level — see how each is routed.
        System.out.println("Scenario 1: route by severity");
        log.debug("cache warm complete");   // console only
        log.info("server started");         // console only
        log.warn("high memory usage");      // console + app.log
        log.error("db connection failed");  // console + app.log + error.log + ALERT

        // 2) Runtime level change: raise the bar to INFO — debug is dropped.
        System.out.println("\nScenario 2: raise min level to INFO (debug dropped)");
        log.setMinLevel(LogLevel.INFO);
        log.debug("this debug is filtered out");
        log.info("still visible");

        // 3) Same logger everywhere (Singleton).
        System.out.println("\nScenario 3: Singleton — same instance");
        System.out.println("  same instance? " + (Logger.getInstance() == log));

        System.out.println();
        counter.printSummary();
    }
}
