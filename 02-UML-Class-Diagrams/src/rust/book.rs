/// Composition target: Library owns Books
/// Association source: Book references an Author (by name, since Rust doesn't do shared refs easily)
///
/// NOTE: Rust doesn't have inheritance. We use a trait (Displayable) + enum for
/// Book variants instead. This is idiomatic Rust.

pub enum BookKind {
    Physical,
    Digital { format: String, file_size_mb: f64 },
}

pub struct Book {
    title: String,
    isbn: String,
    author_name: String, // Stores author name (association by value in Rust)
    kind: BookKind,
}

impl Book {
    pub fn new(title: &str, isbn: &str, author_name: &str) -> Self {
        Book {
            title: title.to_string(),
            isbn: isbn.to_string(),
            author_name: author_name.to_string(),
            kind: BookKind::Physical,
        }
    }

    pub fn new_digital(title: &str, isbn: &str, author_name: &str, format: &str, file_size_mb: f64) -> Self {
        Book {
            title: title.to_string(),
            isbn: isbn.to_string(),
            author_name: author_name.to_string(),
            kind: BookKind::Digital {
                format: format.to_string(),
                file_size_mb,
            },
        }
    }

    pub fn title(&self) -> &str {
        &self.title
    }

    pub fn isbn(&self) -> &str {
        &self.isbn
    }

    pub fn author_name(&self) -> &str {
        &self.author_name
    }

    pub fn display_info(&self) {
        match &self.kind {
            BookKind::Physical => {
                println!("[Book] {} by {} (ISBN: {})", self.title, self.author_name, self.isbn);
            }
            BookKind::Digital { format, file_size_mb } => {
                println!(
                    "[DigitalBook] {} by {} | Format: {} | Size: {}MB",
                    self.title, self.author_name, format, file_size_mb
                );
            }
        }
    }
}
