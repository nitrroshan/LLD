package main

// TextEditor is the Originator — it snapshots and restores its own state.
type TextEditor struct {
	content string
}

func (e *TextEditor) Type(text string) {
	e.content += text
}

func (e *TextEditor) Content() string {
	return e.content
}

// Save snapshots the current state into a memento.
func (e *TextEditor) Save(label string) *EditorMemento {
	return &EditorMemento{content: e.content, label: label}
}

// Restore resets state from a previously created memento.
func (e *TextEditor) Restore(memento *EditorMemento) {
	e.content = memento.content
}
