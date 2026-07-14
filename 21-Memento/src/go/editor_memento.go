package main

// EditorMemento is the Memento — an immutable snapshot. Its state field is
// unexported, so the caretaker can hold it but cannot read the content.
// Only code in this package (the originator) reads `content`.
type EditorMemento struct {
	content string
	label   string
}

// Label is safe metadata the caretaker may display without seeing the state.
func (m *EditorMemento) Label() string {
	return m.label
}
