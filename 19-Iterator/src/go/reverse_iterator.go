package main

// ReverseIterator walks the playlist back to front. Same interface as
// ForwardIterator, so client code is identical regardless of direction.
type ReverseIterator struct {
	songs []Song
	index int
}

func (r *ReverseIterator) HasNext() bool {
	return r.index >= 0
}

func (r *ReverseIterator) Next() Song {
	song := r.songs[r.index]
	r.index--
	return song
}
