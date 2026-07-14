/// A trait with a default method IS the Template Method in Rust: the default
/// `prepare_recipe` fixes the skeleton and calls the required steps and the
/// `wants_condiments` hook. Implementors provide only the varying steps.
pub trait CaffeineBeverage {
    // Varying steps — implementors must supply these.
    fn brew(&self);
    fn add_condiments(&self);

    // Hook — default a type may override.
    fn wants_condiments(&self) -> bool {
        true
    }

    // Template method — the fixed skeleton and ordering.
    fn prepare_recipe(&self) {
        boil_water();
        self.brew();
        pour_in_cup();
        if self.wants_condiments() {
            self.add_condiments();
        }
    }
}

// Invariant steps — shared by all beverages.
fn boil_water() {
    println!("  Boiling water");
}

fn pour_in_cup() {
    println!("  Pouring into cup");
}
