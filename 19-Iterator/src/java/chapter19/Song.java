package chapter19;

/**
 * The element stored in the collection.
 */
public class Song {
    private final String title;
    private final String artist;

    public Song(String title, String artist) {
        this.title = title;
        this.artist = artist;
    }

    @Override
    public String toString() {
        return "\"" + title + "\" by " + artist;
    }
}
