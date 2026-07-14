#pragma once
#include "LogRecord.h"

// Observer — reacts to every accepted log record, off the write path.
class LogObserver {
public:
    virtual ~LogObserver() = default;
    virtual void on_log(const LogRecord& record) = 0;
};
