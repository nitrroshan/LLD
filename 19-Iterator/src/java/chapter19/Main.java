package chapter19;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Iterator Pattern Demo ===\n");

        Playlist playlist = new Playlist();
        playlist.addSong(new Song("Bohemian Rhapsody", "Queen"));
        playlist.addSong(new Song("Hotel California", "Eagles"));
        playlist.addSong(new Song("Stairway to Heaven", "Led Zeppelin"));

        // Forward traversal — client never sees the internal list
        System.out.println("Forward:");
        printAll(playlist.iterator());

        // Reverse traversal — SAME client code shape, different iterator
        System.out.println("\nReverse:");
        printAll(playlist.reverseIterator());

        // Two independent forward iterators — separate cursors
        System.out.println("\nTwo independent cursors:");
        Iterator<Song> a = playlist.iterator();
        Iterator<Song> b = playlist.iterator();
        System.out.println("  a.next(): " + a.next());
        System.out.println("  a.next(): " + a.next());
        System.out.println("  b.next(): " + b.next() + "   (b is unaffected by a)");
    }

    // Works with ANY iterator — the whole point of the pattern.
    static void printAll(Iterator<Song> it) {
        while (it.hasNext()) {
            System.out.println("  " + it.next());
        }
    }
}
