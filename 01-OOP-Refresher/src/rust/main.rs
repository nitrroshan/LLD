// ============================================================
// Chapter 01 — OOP Refresher in Rust
// Run: rustc main.rs && ./main
//
// Structure mirrors Java: one file per struct/trait
//   animal.rs, dog.rs, cat.rs, bank_account.rs,
//   drawable.rs, circle.rs, rectangle.rs, calculator.rs
//
// NOTE: Rust uses traits instead of inheritance.
// Polymorphism via trait objects (dyn Trait) = dynamic dispatch.
// ============================================================

mod bank_account;
mod animal;
mod dog;
mod cat;
mod drawable;
mod circle;
mod rectangle;
mod calculator;

use bank_account::BankAccount;
use animal::Animal;
use dog::Dog;
use cat::Cat;
use drawable::Drawable;
use circle::Circle;
use rectangle::Rectangle;
use calculator::Calculator;

fn main() {
    println!("=== ENCAPSULATION ===");
    let mut account = BankAccount::new("Alice", 1000.0);
    account.deposit(500.0);
    account.withdraw(200.0);
    account.withdraw(5000.0);
    println!("Balance: {}", account.get_balance());

    println!("\n=== TRAITS & POLYMORPHISM ===");
    let animals: Vec<Box<dyn Animal>> = vec![
        Box::new(Dog::new("Buddy", "Golden Retriever")),
        Box::new(Cat::new("Whiskers")),
        Box::new(Dog::new("Rex", "German Shepherd")),
    ];

    for animal in &animals {
        animal.eat();
        animal.make_sound();
        println!();
    }

    println!("=== ABSTRACTION (Trait Objects) ===");
    let drawables: Vec<Box<dyn Drawable>> = vec![
        Box::new(Circle { radius: 5.0 }),
        Box::new(Rectangle { width: 4.0, height: 6.0 }),
    ];

    for d in &drawables {
        d.draw();
        println!("Area: {}", d.area());
        println!();
    }

    println!("=== NO OVERLOADING — Use different names or generics ===");
    let calc = Calculator;
    println!("add_i32(2, 3)     = {}", calc.add_i32(2, 3));
    println!("add_f64(2.5, 3.5) = {}", calc.add_f64(2.5, 3.5));
    println!("add_three(1,2,3)  = {}", calc.add_three(1, 2, 3));
}
