package chapter19;

import java.util.List;

/**
 * Concrete Iterator — walks the playlist back to front. Same interface as
 * ForwardIterator, so client code is identical regardless of direction.
 */
public class ReverseIterator implements Iterator<Song> {
    private final List<Song> songs;
    private int index;

    public ReverseIterator(List<Song> songs) {
        this.songs = songs;
        this.index = songs.size() - 1;
    }

    @Override
    public boolean hasNext() {
        return index >= 0;
    }

    @Override
    public Song next() {
        return songs.get(index--);
    }
}
