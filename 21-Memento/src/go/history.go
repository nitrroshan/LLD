package main

// History is the Caretaker — stores mementos on a stack for undo. It never
// reads the state inside a memento; it only holds and returns them.
type History struct {
	mementos []*EditorMemento
}

func (h *History) Push(memento *EditorMemento) {
	h.mementos = append(h.mementos, memento)
}

func (h *History) Pop() *EditorMemento {
	last := h.mementos[len(h.mementos)-1]
	h.mementos = h.mementos[:len(h.mementos)-1]
	return last
}

func (h *History) IsEmpty() bool {
	return len(h.mementos) == 0
}
