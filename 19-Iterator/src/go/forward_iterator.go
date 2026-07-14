package main

// ForwardIterator walks the playlist front to back. Its own cursor lives
// here, so multiple forward iterators can run independently.
type ForwardIterator struct {
	songs []Song
	index int
}

func (f *ForwardIterator) HasNext() bool {
	return f.index < len(f.songs)
}

func (f *ForwardIterator) Next() Song {
	song := f.songs[f.index]
	f.index++
	return song
}
