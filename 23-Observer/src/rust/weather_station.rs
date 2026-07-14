use std::rc::Rc;

use crate::observer::Observer;

/// Concrete Subject — holds the temperature and pushes updates to every
/// registered observer. Observers are shared trait objects (`Rc<dyn Observer>`).
pub struct WeatherStation {
    observers: Vec<Rc<dyn Observer>>,
    temperature: f64,
}

impl WeatherStation {
    pub fn new() -> Self {
        WeatherStation { observers: Vec::new(), temperature: 0.0 }
    }

    pub fn set_temperature(&mut self, temperature: f64) {
        self.temperature = temperature;
        println!("WeatherStation: temperature -> {:.1}°C", temperature);
        self.notify_observers();
    }

    pub fn register_observer(&mut self, observer: Rc<dyn Observer>) {
        self.observers.push(observer);
    }

    pub fn remove_observer(&mut self, observer: &Rc<dyn Observer>) {
        // Compare by pointer identity to unsubscribe the exact observer.
        self.observers.retain(|o| !Rc::ptr_eq(o, observer));
    }

    pub fn notify_observers(&self) {
        // Clone the handles (cheap Rc bumps) so an observer could unsubscribe
        // during notification without corrupting the loop.
        let snapshot: Vec<Rc<dyn Observer>> = self.observers.clone();
        for observer in snapshot {
            observer.update(self.temperature);
        }
    }
}
