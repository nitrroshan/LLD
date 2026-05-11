// Chapter 03 — SOLID Principles in Rust
// Run: rustc main.rs && ./main

mod srp;
mod ocp;
mod lsp;
mod isp;
mod dip;

use srp::*;
use ocp::*;
use lsp::*;
use isp::*;
use dip::*;

fn main() {
    println!("=== S — Single Responsibility ===");
    let inv = Invoice::new("Keyboard", 2, 49.99);
    InvoicePrinter::print(&inv);
    InvoiceRepository::save(&inv);

    println!("\n=== O — Open/Closed ===");
    let amount = 1000.0;
    println!("Regular:  ${:.0}", calculate_discount(&RegularDiscount, amount));
    println!("Premium:  ${:.0}", calculate_discount(&PremiumDiscount, amount));
    println!("VIP:      ${:.0}", calculate_discount(&VIPDiscount, amount));
    println!("Employee: ${:.0}", calculate_discount(&EmployeeDiscount, amount));

    println!("\n=== L — Liskov Substitution ===");
    let sparrow = Sparrow;
    let penguin = Penguin;
    make_fly(&sparrow);
    // make_fly(&penguin);  // won't compile — Penguin doesn't implement Flyable
    penguin.swim();

    println!("\n=== I — Interface Segregation ===");
    let printer = SimplePrinter;
    printer.print("report.pdf");
    let aio = AllInOnePrinter;
    aio.print("report.pdf");
    aio.scan("photo.jpg");
    aio.fax("contract.pdf");

    println!("\n=== D — Dependency Inversion ===");
    let mysql = MySQL;
    let postgres = PostgreSQL;
    let inmem = InMemoryDB;
    OrderService::new(&mysql).place_order("Laptop");
    OrderService::new(&postgres).place_order("Phone");
    OrderService::new(&inmem).place_order("Tablet");
}
