use crate::beverage::CaffeineBeverage;

/// Fills in the varying steps for tea.
pub struct Tea;

impl CaffeineBeverage for Tea {
    fn brew(&self) {
        println!("  Steeping the tea");
    }

    fn add_condiments(&self) {
        println!("  Adding lemon");
    }
}
