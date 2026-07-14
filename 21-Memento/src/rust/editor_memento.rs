/// Memento — an immutable snapshot. `content` is private; the originator
/// reads it via the crate-visible `content()`, while the caretaker only sees
/// the public `label()`. By discipline, the caretaker never calls `content()`.
pub struct EditorMemento {
    content: String,
    label: String,
}

impl EditorMemento {
    pub(crate) fn new(content: String, label: String) -> Self {
        EditorMemento { content, label }
    }

    // Read by the Originator to restore state.
    pub(crate) fn content(&self) -> &str {
        &self.content
    }

    // Safe metadata for the caretaker to display, without exposing the state.
    pub fn label(&self) -> &str {
        &self.label
    }
}
