// Chapter 05 — Factory Method Pattern in C++
// Compile: g++ -std=c++17 -o main main.cpp && ./main

#include <iostream>
#include <vector>
#include <memory>
#include "LogisticsFactory.h"

int main() {
    std::cout << "=== Road Logistics ===\n";
    RoadLogistics road;
    road.planDelivery();

    std::cout << "\n=== Sea Logistics ===\n";
    SeaLogistics sea;
    sea.planDelivery();

    std::cout << "\n=== Air Logistics ===\n";
    AirLogistics air;
    air.planDelivery();

    std::cout << "\n=== All Logistics (polymorphism) ===\n";
    std::vector<const LogisticsFactory*> factories = {&road, &sea, &air};
    for (const auto* f : factories) {
        f->planDelivery();
    }

    return 0;
}
