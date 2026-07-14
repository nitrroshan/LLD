#pragma once
#include <memory>
#include "LogLevel.h"
#include "LogRecord.h"
#include "Formatter.h"
#include "Appender.h"

// Chain of Responsibility — a handler with a severity threshold, a formatter,
// and an appender. A record flows through the chain; each handler writes it via
// its appender when the record's severity meets the threshold, then forwards to
// the next handler regardless. Each handler owns its appender and the next link.
class LogHandler {
    LogLevel threshold_;
    Formatter* formatter_;                     // non-owning (shared formatter)
    std::unique_ptr<Appender> appender_;       // owns its destination
    std::unique_ptr<LogHandler> next_;

public:
    LogHandler(LogLevel threshold, Formatter* formatter, std::unique_ptr<Appender> appender)
        : threshold_(threshold), formatter_(formatter), appender_(std::move(appender)) {}

    // Wire the next handler; returns a raw pointer for fluent chaining.
    LogHandler* set_next(std::unique_ptr<LogHandler> next) {
        next_ = std::move(next);
        return next_.get();
    }

    void handle(const LogRecord& record) {
        if (severity(record.level()) >= severity(threshold_)) {
            appender_->append(formatter_->format(record));
        }
        if (next_) next_->handle(record);
    }
};
