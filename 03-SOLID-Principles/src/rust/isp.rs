/// ISP — Interface Segregation Principle
/// Small focused traits instead of one fat trait

pub trait Printable {
    fn print(&self, doc: &str);
}

pub trait Scannable {
    fn scan(&self, doc: &str);
}

pub trait Faxable {
    fn fax(&self, doc: &str);
}

pub struct AllInOnePrinter;
impl Printable for AllInOnePrinter {
    fn print(&self, doc: &str) { println!("Printing: {}", doc); }
}
impl Scannable for AllInOnePrinter {
    fn scan(&self, doc: &str) { println!("Scanning: {}", doc); }
}
impl Faxable for AllInOnePrinter {
    fn fax(&self, doc: &str) { println!("Faxing: {}", doc); }
}

pub struct SimplePrinter;
impl Printable for SimplePrinter {
    fn print(&self, doc: &str) { println!("Printing: {}", doc); }
}
// SimplePrinter doesn't implement Scannable or Faxable — compiler enforces ISP
