#pragma once
#include <memory>
#include <vector>
#include <string>
#include "LogHandler.h"
#include "LogObserver.h"
#include "LogLevel.h"
#include "LogRecord.h"

// Singleton — the global logger (Meyer's Singleton: lazy + thread-safe init).
// Holds the handler chain (Chain of Responsibility), observers (Observer), and
// a global minimum level.
class Logger {
    std::unique_ptr<LogHandler> chain_;
    std::vector<std::unique_ptr<LogObserver>> observers_;
    LogLevel min_level_ = LogLevel::Debug;
    long clock_ = 0;   // deterministic timestamp for the demo

    Logger() = default;

public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& instance() {
        static Logger logger;
        return logger;
    }

    void set_chain(std::unique_ptr<LogHandler> chain) { chain_ = std::move(chain); }
    void add_observer(std::unique_ptr<LogObserver> observer) { observers_.push_back(std::move(observer)); }
    void set_min_level(LogLevel level) { min_level_ = level; }

    void log(LogLevel level, const std::string& message) {
        if (severity(level) < severity(min_level_)) return;   // gated out early
        LogRecord record(level, message, ++clock_);
        if (chain_) chain_->handle(record);                   // Chain of Responsibility
        for (auto& observer : observers_) observer->on_log(record);   // Observer
    }

    void debug(const std::string& m) { log(LogLevel::Debug, m); }
    void info(const std::string& m) { log(LogLevel::Info, m); }
    void warn(const std::string& m) { log(LogLevel::Warn, m); }
    void error(const std::string& m) { log(LogLevel::Error, m); }
};
