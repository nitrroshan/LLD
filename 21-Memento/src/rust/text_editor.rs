use crate::editor_memento::EditorMemento;

/// Originator — snapshots and restores its own private state.
pub struct TextEditor {
    content: String,
}

impl TextEditor {
    pub fn new() -> Self {
        TextEditor { content: String::new() }
    }

    // `type` is a Rust keyword, so the method is named `type_text`.
    pub fn type_text(&mut self, text: &str) {
        self.content.push_str(text);
    }

    pub fn content(&self) -> &str {
        &self.content
    }

    /// Snapshot the current state into a memento.
    pub fn save(&self, label: &str) -> EditorMemento {
        EditorMemento::new(self.content.clone(), label.to_string())
    }

    /// Restore state from a previously created memento.
    pub fn restore(&mut self, memento: &EditorMemento) {
        self.content = memento.content().to_string();
    }
}
