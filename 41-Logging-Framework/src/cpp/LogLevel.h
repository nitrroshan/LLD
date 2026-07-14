#pragma once
#include <string>

// Log levels in ascending severity.
enum class LogLevel { Debug = 1, Info = 2, Warn = 3, Error = 4 };

inline int severity(LogLevel l) { return static_cast<int>(l); }

inline std::string to_string(LogLevel l) {
    switch (l) {
        case LogLevel::Debug: return "DEBUG";
        case LogLevel::Info:  return "INFO";
        case LogLevel::Warn:  return "WARN";
        case LogLevel::Error: return "ERROR";
    }
    return "?";
}
