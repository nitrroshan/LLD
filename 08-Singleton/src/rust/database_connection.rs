use std::collections::HashMap;
use std::sync::OnceLock;

pub struct DatabaseConnection {
    host: String,
    port: u16,
    connected: bool,
}

// Global singleton using OnceLock (stable since Rust 1.80).
// OnceLock guarantees thread-safe, lazy, one-time initialization.
// We use a Mutex to allow interior mutability (connect/disconnect).
static DB_INSTANCE: OnceLock<std::sync::Mutex<DatabaseConnection>> = OnceLock::new();

impl DatabaseConnection {
    fn new() -> Self {
        DatabaseConnection {
            host: String::from("localhost"),
            port: 5432,
            connected: false,
        }
    }

    pub fn get_instance() -> &'static std::sync::Mutex<DatabaseConnection> {
        DB_INSTANCE.get_or_init(|| std::sync::Mutex::new(DatabaseConnection::new()))
    }

    pub fn connect(&mut self) {
        if !self.connected {
            self.connected = true;
            println!("Connected to {}:{}", self.host, self.port);
        } else {
            println!("Already connected to {}:{}", self.host, self.port);
        }
    }

    pub fn disconnect(&mut self) {
        if self.connected {
            self.connected = false;
            println!("Disconnected from {}:{}", self.host, self.port);
        }
    }

    pub fn query(&self, sql: &str) -> String {
        if !self.connected {
            panic!("Not connected — call connect() first");
        }
        format!("Result of: {}", sql)
    }

    pub fn is_connected(&self) -> bool {
        self.connected
    }
}

impl std::fmt::Display for DatabaseConnection {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "DatabaseConnection[{}:{}, connected={}]",
            self.host, self.port, self.connected
        )
    }
}
