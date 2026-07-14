package main

// Iterator declares sequential access. HasNext reports whether more elements
// remain; Next returns the current one and advances the cursor.
type Iterator interface {
	HasNext() bool
	Next() Song
}
