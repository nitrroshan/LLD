#pragma once
#include <iostream>
#include <string>

// ISP — Interface Segregation Principle
// Small focused interfaces instead of one fat interface

namespace isp {

struct Printable {
    virtual ~Printable() = default;
    virtual void print(const std::string& doc) const = 0;
};

struct Scannable {
    virtual ~Scannable() = default;
    virtual void scan(const std::string& doc) const = 0;
};

struct Faxable {
    virtual ~Faxable() = default;
    virtual void fax(const std::string& doc) const = 0;
};

struct AllInOnePrinter : Printable, Scannable, Faxable {
    void print(const std::string& doc) const override { std::cout << "Printing: " << doc << "\n"; }
    void scan(const std::string& doc) const override { std::cout << "Scanning: " << doc << "\n"; }
    void fax(const std::string& doc) const override { std::cout << "Faxing: " << doc << "\n"; }
};

struct SimplePrinter : Printable {
    void print(const std::string& doc) const override { std::cout << "Printing: " << doc << "\n"; }
    // No scan, no fax — only implements what it can do
};

inline void demo() {
    SimplePrinter printer;
    printer.print("report.pdf");

    AllInOnePrinter aio;
    aio.print("report.pdf");
    aio.scan("photo.jpg");
    aio.fax("contract.pdf");
}

} // namespace isp
