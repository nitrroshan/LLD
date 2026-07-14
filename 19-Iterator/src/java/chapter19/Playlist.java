package chapter19;

import java.util.ArrayList;
import java.util.List;

/**
 * Aggregate — the collection. It stores songs however it likes (here a List)
 * and vends iterators so clients never touch the internal storage.
 */
public class Playlist {
    private final List<Song> songs = new ArrayList<>();

    public void addSong(Song song) {
        songs.add(song);
    }

    public Iterator<Song> iterator() {
        return new ForwardIterator(songs);
    }

    public Iterator<Song> reverseIterator() {
        return new ReverseIterator(songs);
    }
}
