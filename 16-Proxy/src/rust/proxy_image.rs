use std::cell::RefCell;

use crate::image::Image;
use crate::real_image::RealImage;

/// Virtual Proxy — same trait as RealImage, defers the expensive load until
/// `display` is first called. `display` takes `&self`, so we need interior
/// mutability (`RefCell`) to create and store the real image lazily.
pub struct ProxyImage {
    filename: String,
    real_image: RefCell<Option<RealImage>>,
}

impl ProxyImage {
    pub fn new(filename: &str) -> Self {
        println!("  [ProxyImage] Created for {} (nothing loaded yet)", filename);
        ProxyImage {
            filename: filename.to_string(),
            real_image: RefCell::new(None),
        }
    }
}

impl Image for ProxyImage {
    fn display(&self) {
        // Create the real image on first display only
        if self.real_image.borrow().is_none() {
            *self.real_image.borrow_mut() = Some(RealImage::new(&self.filename));
        }
        self.real_image.borrow().as_ref().unwrap().display();
    }
}
