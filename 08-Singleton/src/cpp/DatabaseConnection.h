#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <stdexcept>

// Meyer's Singleton — C++11 guarantees thread-safe local static initialization.
// This is the recommended C++ approach.
class DatabaseConnection {
private:
    std::string host_;
    int port_;
    bool connected_;

    // Private constructor
    DatabaseConnection() : host_("localhost"), port_(5432), connected_(false) {}

public:
    // Delete copy and move — prevent duplication
    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;
    DatabaseConnection(DatabaseConnection&&) = delete;
    DatabaseConnection& operator=(DatabaseConnection&&) = delete;

    static DatabaseConnection& get_instance() {
        static DatabaseConnection instance;  // Thread-safe since C++11
        return instance;
    }

    void connect() {
        if (!connected_) {
            connected_ = true;
            std::cout << "Connected to " << host_ << ":" << port_ << "\n";
        } else {
            std::cout << "Already connected to " << host_ << ":" << port_ << "\n";
        }
    }

    void disconnect() {
        if (connected_) {
            connected_ = false;
            std::cout << "Disconnected from " << host_ << ":" << port_ << "\n";
        }
    }

    std::string query(const std::string& sql) {
        if (!connected_) {
            throw std::runtime_error("Not connected — call connect() first");
        }
        return "Result of: " + sql;
    }

    bool is_connected() const { return connected_; }

    friend std::ostream& operator<<(std::ostream& os, const DatabaseConnection& db) {
        os << "DatabaseConnection[" << db.host_ << ":" << db.port_
           << ", connected=" << (db.connected_ ? "true" : "false") << "]";
        return os;
    }
};
