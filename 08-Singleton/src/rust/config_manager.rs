use std::collections::HashMap;
use std::sync::OnceLock;

pub struct ConfigManager {
    properties: HashMap<String, String>,
}

static CONFIG_INSTANCE: OnceLock<std::sync::Mutex<ConfigManager>> = OnceLock::new();

impl ConfigManager {
    fn new() -> Self {
        let mut cm = ConfigManager {
            properties: HashMap::new(),
        };
        cm.load_defaults();
        cm
    }

    fn load_defaults(&mut self) {
        self.properties.insert("app.name".into(), "LLD Learning App".into());
        self.properties.insert("app.version".into(), "1.0".into());
        self.properties.insert("db.host".into(), "localhost".into());
        self.properties.insert("db.port".into(), "5432".into());
        self.properties.insert("log.level".into(), "INFO".into());
    }

    pub fn get_instance() -> &'static std::sync::Mutex<ConfigManager> {
        CONFIG_INSTANCE.get_or_init(|| std::sync::Mutex::new(ConfigManager::new()))
    }

    pub fn get(&self, key: &str) -> Option<&String> {
        self.properties.get(key)
    }

    pub fn set(&mut self, key: &str, value: &str) {
        self.properties.insert(key.into(), value.into());
    }

    pub fn size(&self) -> usize {
        self.properties.len()
    }
}
