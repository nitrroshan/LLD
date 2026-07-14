#pragma once
#include <string>
#include "LogLevel.h"

// An immutable log record: level, message, and a timestamp.
class LogRecord {
    LogLevel level_;
    std::string message_;
    long timestamp_;
public:
    LogRecord(LogLevel level, std::string message, long timestamp)
        : level_(level), message_(std::move(message)), timestamp_(timestamp) {}
    LogLevel level() const { return level_; }
    const std::string& message() const { return message_; }
    long timestamp() const { return timestamp_; }
};
