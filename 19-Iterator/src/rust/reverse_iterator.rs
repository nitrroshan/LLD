use crate::song::Song;

/// Concrete Iterator — walks the playlist back to front. Same `Iterator`
/// trait, so client code is identical regardless of direction.
pub struct ReverseIterator<'a> {
    songs: &'a [Song],
    index: isize,
}

impl<'a> ReverseIterator<'a> {
    pub fn new(songs: &'a [Song]) -> Self {
        ReverseIterator { songs, index: songs.len() as isize - 1 }
    }
}

impl<'a> Iterator for ReverseIterator<'a> {
    type Item = &'a Song;

    fn next(&mut self) -> Option<&'a Song> {
        if self.index >= 0 {
            let song = &self.songs[self.index as usize];
            self.index -= 1;
            Some(song)
        } else {
            None
        }
    }
}
