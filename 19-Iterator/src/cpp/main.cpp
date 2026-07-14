#include <iostream>
#include <memory>
#include "Song.h"
#include "Iterator.h"
#include "Playlist.h"

// Works with ANY iterator — the whole point of the pattern.
void print_all(std::unique_ptr<Iterator> it) {
    while (it->has_next()) {
        std::cout << "  " << it->next().to_string() << "\n";
    }
}

int main() {
    std::cout << "=== Iterator Pattern Demo (C++) ===\n\n";

    Playlist playlist;
    playlist.add_song(Song("Bohemian Rhapsody", "Queen"));
    playlist.add_song(Song("Hotel California", "Eagles"));
    playlist.add_song(Song("Stairway to Heaven", "Led Zeppelin"));

    std::cout << "Forward:\n";
    print_all(playlist.iterator());

    std::cout << "\nReverse:\n";
    print_all(playlist.reverse_iterator());

    std::cout << "\nTwo independent cursors:\n";
    auto a = playlist.iterator();
    auto b = playlist.iterator();
    std::cout << "  a.next(): " << a->next().to_string() << "\n";
    std::cout << "  a.next(): " << a->next().to_string() << "\n";
    std::cout << "  b.next(): " << b->next().to_string() << "   (b is unaffected by a)\n";

    return 0;
}
