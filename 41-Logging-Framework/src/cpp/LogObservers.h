#pragma once
#include <iostream>
#include <map>
#include "LogObserver.h"
#include "LogLevel.h"

// Observer — counts records by level (a stand-in for a metrics dashboard).
class LogCountObserver : public LogObserver {
    std::map<int, int> counts_;   // severity -> count
public:
    void on_log(const LogRecord& record) override {
        counts_[severity(record.level())]++;
    }
    void print_summary() const {
        std::cout << "  Log counts:";
        for (LogLevel level : {LogLevel::Debug, LogLevel::Info, LogLevel::Warn, LogLevel::Error}) {
            auto it = counts_.find(severity(level));
            std::cout << " " << to_string(level) << "=" << (it == counts_.end() ? 0 : it->second);
        }
        std::cout << "\n";
    }
};

// Observer — fires an alert whenever an ERROR is logged.
class AlertObserver : public LogObserver {
public:
    void on_log(const LogRecord& record) override {
        if (record.level() == LogLevel::Error) {
            std::cout << "  *** ALERT: " << record.message() << " ***\n";
        }
    }
};
