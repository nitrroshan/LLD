use crate::image::Image;

/// RealSubject — the expensive object. The costly load is simulated in `new`.
pub struct RealImage {
    filename: String,
}

impl RealImage {
    pub fn new(filename: &str) -> Self {
        let image = RealImage { filename: filename.to_string() };
        image.load_from_disk();
        image
    }

    fn load_from_disk(&self) {
        println!("  [RealImage] Loading {} from disk (expensive)...", self.filename);
    }
}

impl Image for RealImage {
    fn display(&self) {
        println!("  [RealImage] Displaying {}", self.filename);
    }
}
