use crate::editor_memento::EditorMemento;

/// Caretaker — stores mementos on a stack for undo. It never reads the state
/// inside a memento; it only holds and returns them.
pub struct History {
    mementos: Vec<EditorMemento>,
}

impl History {
    pub fn new() -> Self {
        History { mementos: Vec::new() }
    }

    pub fn push(&mut self, memento: EditorMemento) {
        self.mementos.push(memento);
    }

    pub fn pop(&mut self) -> Option<EditorMemento> {
        self.mementos.pop()
    }

    pub fn is_empty(&self) -> bool {
        self.mementos.is_empty()
    }
}
