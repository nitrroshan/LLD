#pragma once
#include <iostream>
#include <string>
#include <memory>

// DIP — Dependency Inversion Principle
// High-level modules depend on abstractions, not concretions

namespace dip {

struct Database {
    virtual ~Database() = default;
    virtual void save(const std::string& data) const = 0;
};

struct MySQL : Database {
    void save(const std::string& data) const override {
        std::cout << "[MySQL] Saved: " << data << "\n";
    }
};

struct PostgreSQL : Database {
    void save(const std::string& data) const override {
        std::cout << "[PostgreSQL] Saved: " << data << "\n";
    }
};

struct InMemoryDB : Database {
    void save(const std::string& data) const override {
        std::cout << "[InMemory] Saved: " << data << "\n";
    }
};

class OrderService {
    const Database& db;  // depends on abstraction (reference)
public:
    OrderService(const Database& db) : db(db) {}

    void placeOrder(const std::string& order) const {
        std::cout << "Placing order: " << order << "\n";
        db.save(order);
    }
};

inline void demo() {
    MySQL mysql;
    PostgreSQL postgres;
    InMemoryDB inmem;

    OrderService s1(mysql);    s1.placeOrder("Laptop");
    OrderService s2(postgres); s2.placeOrder("Phone");
    OrderService s3(inmem);    s3.placeOrder("Tablet");
}

} // namespace dip
