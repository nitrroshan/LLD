use crate::beverage::CaffeineBeverage;

/// Black coffee overrides the hook to skip condiments.
pub struct BlackCoffee;

impl CaffeineBeverage for BlackCoffee {
    fn brew(&self) {
        println!("  Dripping coffee through filter");
    }

    fn add_condiments(&self) {
        // no condiments
    }

    fn wants_condiments(&self) -> bool {
        false // hook overridden — the condiment step is skipped
    }
}
