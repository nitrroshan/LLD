package chapter19;

import java.util.List;

/**
 * Concrete Iterator — walks the playlist front to back. Its own cursor
 * (index) lives here, so multiple forward iterators can run independently.
 */
public class ForwardIterator implements Iterator<Song> {
    private final List<Song> songs;
    private int index = 0;

    public ForwardIterator(List<Song> songs) {
        this.songs = songs;
    }

    @Override
    public boolean hasNext() {
        return index < songs.size();
    }

    @Override
    public Song next() {
        return songs.get(index++);
    }
}
