#include <iostream>
#include "DatabaseConnection.h"
#include "ConfigManager.h"

int main() {
    std::cout << "=== Singleton Pattern Demo (C++) ===\n\n";

    // 1. DatabaseConnection Singleton
    std::cout << "--- DatabaseConnection Singleton ---\n";
    auto& db1 = DatabaseConnection::get_instance();
    auto& db2 = DatabaseConnection::get_instance();
    std::cout << "Same instance? " << (&db1 == &db2 ? "true" : "false") << "\n";

    db1.connect();
    db2.connect();  // Already connected — same instance!
    std::cout << db1.query("SELECT * FROM users") << "\n";
    db1.disconnect();
    std::cout << "\n";

    // 2. ConfigManager Singleton
    std::cout << "--- ConfigManager Singleton ---\n";
    auto& config1 = ConfigManager::get_instance();
    auto& config2 = ConfigManager::get_instance();
    std::cout << "Same instance? " << (&config1 == &config2 ? "true" : "false") << "\n";
    std::cout << "app.name = " << config1.get("app.name") << "\n";
    config1.set("app.name", "Updated App");
    std::cout << "app.name (via config2) = " << config2.get("app.name") << "\n";
    // Both references see the change — they're the same object

    return 0;
}
