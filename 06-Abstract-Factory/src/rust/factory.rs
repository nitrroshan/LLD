use crate::products::*;

// Abstract Factory trait — one method per product type
// NOTE: Rust returns trait objects (Box<dyn Trait>) since there's no inheritance
pub trait UIFactory {
    fn create_button(&self) -> Box<dyn Button>;
    fn create_checkbox(&self) -> Box<dyn Checkbox>;
    fn create_menu(&self) -> Box<dyn Menu>;
}

// Concrete Factory — Windows family
pub struct WindowsFactory;
impl UIFactory for WindowsFactory {
    fn create_button(&self) -> Box<dyn Button> { Box::new(WindowsButton) }
    fn create_checkbox(&self) -> Box<dyn Checkbox> { Box::new(WindowsCheckbox) }
    fn create_menu(&self) -> Box<dyn Menu> { Box::new(WindowsMenu) }
}

// Concrete Factory — Mac family
pub struct MacFactory;
impl UIFactory for MacFactory {
    fn create_button(&self) -> Box<dyn Button> { Box::new(MacButton) }
    fn create_checkbox(&self) -> Box<dyn Checkbox> { Box::new(MacCheckbox) }
    fn create_menu(&self) -> Box<dyn Menu> { Box::new(MacMenu) }
}
