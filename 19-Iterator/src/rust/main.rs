mod song;
mod forward_iterator;
mod reverse_iterator;
mod playlist;

use song::Song;
use playlist::Playlist;

// Works with ANY iterator over &Song — the whole point of the pattern.
fn print_all<'a, I: Iterator<Item = &'a Song>>(it: I) {
    for song in it {
        println!("  {}", song);
    }
}

fn main() {
    println!("=== Iterator Pattern Demo (Rust) ===\n");

    let mut playlist = Playlist::new();
    playlist.add_song(Song::new("Bohemian Rhapsody", "Queen"));
    playlist.add_song(Song::new("Hotel California", "Eagles"));
    playlist.add_song(Song::new("Stairway to Heaven", "Led Zeppelin"));

    println!("Forward:");
    print_all(playlist.iter());

    println!("\nReverse:");
    print_all(playlist.reverse_iter());

    // Because our iterator implements the std Iterator trait, adapters
    // like take() work for free — no extra code.
    println!("\nStd adapters for free (first 2 forward):");
    for song in playlist.iter().take(2) {
        println!("  {}", song);
    }

    // Two independent cursors — separate iterators, separate positions.
    println!("\nTwo independent cursors:");
    let mut a = playlist.iter();
    let mut b = playlist.iter();
    println!("  a.next(): {}", a.next().unwrap());
    println!("  a.next(): {}", a.next().unwrap());
    println!("  b.next(): {}   (b is unaffected by a)", b.next().unwrap());
}
