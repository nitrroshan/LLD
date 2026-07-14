/// Observer — the update interface all subscribers implement (push model).
pub trait Observer {
    fn update(&self, temperature: f64);
}
