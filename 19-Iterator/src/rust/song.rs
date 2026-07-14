use std::fmt;

/// The element stored in the collection.
#[derive(Clone)]
pub struct Song {
    title: String,
    artist: String,
}

impl Song {
    pub fn new(title: &str, artist: &str) -> Self {
        Song { title: title.to_string(), artist: artist.to_string() }
    }
}

impl fmt::Display for Song {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "\"{}\" by {}", self.title, self.artist)
    }
}
