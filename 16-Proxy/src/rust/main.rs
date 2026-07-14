mod image;
mod real_image;
mod proxy_image;

use image::Image;
use proxy_image::ProxyImage;

fn main() {
    println!("=== Proxy Pattern Demo (Virtual / Lazy Loading, Rust) ===\n");

    // Creating the proxies is cheap — no disk load happens here
    println!("Creating image proxies (no loading expected):");
    let photo1: Box<dyn Image> = Box::new(ProxyImage::new("vacation.jpg"));
    let _photo2: Box<dyn Image> = Box::new(ProxyImage::new("portrait.jpg"));

    // The heavy load happens only when display() is first called
    println!("\nFirst display of photo1 (triggers load):");
    photo1.display();

    println!("\nSecond display of photo1 (already loaded, no reload):");
    photo1.display();

    println!("\nphoto2 was never displayed — so it was never loaded.");
    println!("That is the point of a virtual proxy: pay the cost only if used.");
}
