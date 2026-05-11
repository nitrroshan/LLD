use crate::book::Book;

/// Realization: Searchable trait (interface in Rust)
pub trait Searchable {
    fn search(&self, title: &str) -> Option<&Book>;
    fn search_by_author(&self, author_name: &str) -> Vec<&Book>;
}
