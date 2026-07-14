use crate::observer::Observer;

/// Concrete Observer — a dashboard that reacts to temperature.
pub struct WindowDisplay;

impl Observer for WindowDisplay {
    fn update(&self, temperature: f64) {
        let advice = if temperature > 25.0 { "open the windows" } else { "keep them closed" };
        println!("  [Window] {:.1}°C — {}", temperature, advice);
    }
}
