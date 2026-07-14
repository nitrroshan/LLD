package main

// Playlist is the Aggregate — it stores songs and vends iterators so clients
// never touch the internal slice.
type Playlist struct {
	songs []Song
}

func (p *Playlist) AddSong(song Song) {
	p.songs = append(p.songs, song)
}

func (p *Playlist) Iterator() Iterator {
	return &ForwardIterator{songs: p.songs, index: 0}
}

func (p *Playlist) ReverseIterator() Iterator {
	return &ReverseIterator{songs: p.songs, index: len(p.songs) - 1}
}
