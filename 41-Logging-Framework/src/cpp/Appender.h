#pragma once
#include <string>
#include <iostream>

// Strategy — a destination for formatted log lines.
class Appender {
public:
    virtual ~Appender() = default;
    virtual void append(const std::string& line) = 0;
};

// Writes lines to the console.
class ConsoleAppender : public Appender {
public:
    void append(const std::string& line) override {
        std::cout << "    [console] " << line << "\n";
    }
};

// Simulated file appender — prints with a [file] tag instead of real I/O.
// (Log rotation would live here, hidden from the handler and logger.)
class FileAppender : public Appender {
    std::string file_name_;
public:
    explicit FileAppender(std::string file_name) : file_name_(std::move(file_name)) {}
    void append(const std::string& line) override {
        std::cout << "    [file:" << file_name_ << "] " << line << "\n";
    }
};
