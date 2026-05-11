// Abstract Products — UI component traits

pub trait Button {
    fn render(&self);
    fn on_click(&self);
}

pub trait Checkbox {
    fn render(&self);
    fn toggle(&self);
}

pub trait Menu {
    fn render(&self);
    fn select(&self, item: &str);
}

// Windows family
pub struct WindowsButton;
impl Button for WindowsButton {
    fn render(&self) { println!("[Windows Button] Rendering flat-style button with sharp corners."); }
    fn on_click(&self) { println!("[Windows Button] Click — executing Windows command."); }
}

pub struct WindowsCheckbox;
impl Checkbox for WindowsCheckbox {
    fn render(&self) { println!("[Windows Checkbox] Rendering square checkbox with checkmark."); }
    fn toggle(&self) { println!("[Windows Checkbox] Toggled — Windows style."); }
}

pub struct WindowsMenu;
impl Menu for WindowsMenu {
    fn render(&self) { println!("[Windows Menu] Rendering dropdown menu with separator lines."); }
    fn select(&self, item: &str) { println!("[Windows Menu] Selected: {} — Windows style.", item); }
}

// Mac family
pub struct MacButton;
impl Button for MacButton {
    fn render(&self) { println!("[Mac Button] Rendering rounded Aqua-style button."); }
    fn on_click(&self) { println!("[Mac Button] Click — executing macOS command."); }
}

pub struct MacCheckbox;
impl Checkbox for MacCheckbox {
    fn render(&self) { println!("[Mac Checkbox] Rendering rounded checkbox with smooth animation."); }
    fn toggle(&self) { println!("[Mac Checkbox] Toggled — macOS style."); }
}

pub struct MacMenu;
impl Menu for MacMenu {
    fn render(&self) { println!("[Mac Menu] Rendering translucent menu with vibrancy effect."); }
    fn select(&self, item: &str) { println!("[Mac Menu] Selected: {} — macOS style.", item); }
}
