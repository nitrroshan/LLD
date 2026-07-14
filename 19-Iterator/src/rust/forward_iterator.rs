use crate::song::Song;

/// Concrete Iterator — walks the playlist front to back. Implementing the
/// standard `Iterator` trait means `for`, `take`, `map`, `filter`, etc.
/// all work for free. `next() -> Option` fuses `hasNext` + `next` into one.
pub struct ForwardIterator<'a> {
    songs: &'a [Song],
    index: usize,
}

impl<'a> ForwardIterator<'a> {
    pub fn new(songs: &'a [Song]) -> Self {
        ForwardIterator { songs, index: 0 }
    }
}

impl<'a> Iterator for ForwardIterator<'a> {
    type Item = &'a Song;

    fn next(&mut self) -> Option<&'a Song> {
        if self.index < self.songs.len() {
            let song = &self.songs[self.index];
            self.index += 1;
            Some(song)
        } else {
            None
        }
    }
}
