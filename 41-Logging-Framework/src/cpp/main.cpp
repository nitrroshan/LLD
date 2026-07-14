#include <iostream>
#include <memory>
#include "Logger.h"
#include "LogHandler.h"
#include "Formatter.h"
#include "Appender.h"
#include "LogObservers.h"
#include "LogLevel.h"

int main() {
    std::cout << "=== Logging Framework Demo (C++) ===\n\n";

    Logger& log = Logger::instance();

    // A shared formatter with program-long lifetime (static), referenced by the
    // handlers (non-owning). Meyer's-singleton-style storage keeps it alive.
    static SimpleFormatter simple;

    // Chain of Responsibility: console(DEBUG) -> file(WARN) -> file(ERROR).
    auto console = std::make_unique<LogHandler>(LogLevel::Debug, &simple, std::make_unique<ConsoleAppender>());
    console->set_next(std::make_unique<LogHandler>(LogLevel::Warn, &simple, std::make_unique<FileAppender>("app.log")))
           ->set_next(std::make_unique<LogHandler>(LogLevel::Error, &simple, std::make_unique<FileAppender>("error.log")));
    log.set_chain(std::move(console));

    // Observers (keep a raw pointer to the counter for the summary).
    auto counter = std::make_unique<LogCountObserver>();
    LogCountObserver* counter_ptr = counter.get();
    log.add_observer(std::move(counter));
    log.add_observer(std::make_unique<AlertObserver>());

    // 1) Log at every level — see how each is routed.
    std::cout << "Scenario 1: route by severity\n";
    log.debug("cache warm complete");   // console only
    log.info("server started");         // console only
    log.warn("high memory usage");      // console + app.log
    log.error("db connection failed");  // console + app.log + error.log + ALERT

    // 2) Runtime level change: raise the bar to INFO — debug is dropped.
    std::cout << "\nScenario 2: raise min level to INFO (debug dropped)\n";
    log.set_min_level(LogLevel::Info);
    log.debug("this debug is filtered out");
    log.info("still visible");

    // 3) Same logger everywhere (Singleton).
    std::cout << "\nScenario 3: Singleton - same instance\n";
    std::cout << "  same instance? " << (&Logger::instance() == &log ? "true" : "false") << "\n";

    std::cout << "\n";
    counter_ptr->print_summary();

    return 0;
}
