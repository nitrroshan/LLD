/// DIP — Dependency Inversion Principle
/// OrderService depends on a Database trait, not a concrete type

pub trait Database {
    fn save(&self, data: &str);
}

pub struct MySQL;
impl Database for MySQL {
    fn save(&self, data: &str) { println!("[MySQL] Saved: {}", data); }
}

pub struct PostgreSQL;
impl Database for PostgreSQL {
    fn save(&self, data: &str) { println!("[PostgreSQL] Saved: {}", data); }
}

pub struct InMemoryDB;
impl Database for InMemoryDB {
    fn save(&self, data: &str) { println!("[InMemory] Saved: {}", data); }
}

pub struct OrderService<'a> {
    db: &'a dyn Database,   // depends on abstraction (trait object reference)
}

impl<'a> OrderService<'a> {
    pub fn new(db: &'a dyn Database) -> Self {
        OrderService { db }
    }

    pub fn place_order(&self, order: &str) {
        println!("Placing order: {}", order);
        self.db.save(order);
    }
}
