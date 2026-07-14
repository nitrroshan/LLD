use crate::beverage::CaffeineBeverage;

/// Fills in the varying steps for coffee.
pub struct Coffee;

impl CaffeineBeverage for Coffee {
    fn brew(&self) {
        println!("  Dripping coffee through filter");
    }

    fn add_condiments(&self) {
        println!("  Adding sugar and milk");
    }
}
