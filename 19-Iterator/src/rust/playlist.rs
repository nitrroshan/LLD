use crate::song::Song;
use crate::forward_iterator::ForwardIterator;
use crate::reverse_iterator::ReverseIterator;

/// Aggregate — stores songs and vends iterators so clients never touch
/// the internal Vec.
pub struct Playlist {
    songs: Vec<Song>,
}

impl Playlist {
    pub fn new() -> Self {
        Playlist { songs: Vec::new() }
    }

    pub fn add_song(&mut self, song: Song) {
        self.songs.push(song);
    }

    pub fn iter(&self) -> ForwardIterator {
        ForwardIterator::new(&self.songs)
    }

    pub fn reverse_iter(&self) -> ReverseIterator {
        ReverseIterator::new(&self.songs)
    }
}
