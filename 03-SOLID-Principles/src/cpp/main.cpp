// Chapter 03 — SOLID Principles in C++
// Compile: g++ -std=c++17 -o main main.cpp && ./main

#include <iostream>
#include "SRP.h"
#include "OCP.h"
#include "LSP.h"
#include "ISP.h"
#include "DIP.h"

int main() {
    std::cout << "=== S — Single Responsibility ===\n";
    srp::demo();

    std::cout << "\n=== O — Open/Closed ===\n";
    ocp::demo();

    std::cout << "\n=== L — Liskov Substitution ===\n";
    lsp::demo();

    std::cout << "\n=== I — Interface Segregation ===\n";
    isp::demo();

    std::cout << "\n=== D — Dependency Inversion ===\n";
    dip::demo();

    return 0;
}
