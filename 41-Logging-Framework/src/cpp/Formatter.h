#pragma once
#include <string>
#include "LogRecord.h"

// Strategy — turns a record into a line of text.
class Formatter {
public:
    virtual ~Formatter() = default;
    virtual std::string format(const LogRecord& record) const = 0;
};

// Plain-text formatter: [t=..][LEVEL] message.
class SimpleFormatter : public Formatter {
public:
    std::string format(const LogRecord& record) const override {
        return "[t=" + std::to_string(record.timestamp()) + "][" + to_string(record.level())
               + "] " + record.message();
    }
};

// Structured (JSON) formatter — same appenders can emit JSON by swapping this in.
class JsonFormatter : public Formatter {
public:
    std::string format(const LogRecord& record) const override {
        return "{\"ts\":" + std::to_string(record.timestamp())
               + ",\"level\":\"" + to_string(record.level()) + "\""
               + ",\"msg\":\"" + record.message() + "\"}";
    }
};
