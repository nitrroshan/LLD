mod database_connection;
mod config_manager;

use database_connection::DatabaseConnection;
use config_manager::ConfigManager;

fn main() {
    println!("=== Singleton Pattern Demo (Rust) ===\n");

    // 1. DatabaseConnection Singleton
    println!("--- DatabaseConnection Singleton ---");
    {
        let mut db = DatabaseConnection::get_instance().lock().unwrap();
        db.connect();
    }
    {
        let mut db = DatabaseConnection::get_instance().lock().unwrap();
        db.connect(); // Already connected — same instance!
        println!("{}", db.query("SELECT * FROM users"));
        db.disconnect();
    }

    // Verify same instance — both calls return the same static reference
    let ptr1 = DatabaseConnection::get_instance() as *const _;
    let ptr2 = DatabaseConnection::get_instance() as *const _;
    println!("Same instance? {}", ptr1 == ptr2);
    println!();

    // 2. ConfigManager Singleton
    println!("--- ConfigManager Singleton ---");
    {
        let config = ConfigManager::get_instance().lock().unwrap();
        println!(
            "app.name = {}",
            config.get("app.name").unwrap()
        );
    }
    {
        let mut config = ConfigManager::get_instance().lock().unwrap();
        config.set("app.name", "Updated App");
    }
    {
        let config = ConfigManager::get_instance().lock().unwrap();
        println!(
            "app.name (after update) = {}",
            config.get("app.name").unwrap()
        );
    }
    let ptr1 = ConfigManager::get_instance() as *const _;
    let ptr2 = ConfigManager::get_instance() as *const _;
    println!("Same instance? {}", ptr1 == ptr2);
}
