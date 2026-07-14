package chapter21;

/**
 * Memento — an immutable snapshot of the editor's state. The caretaker holds
 * it but must treat it as opaque; only the originator reads getContent().
 * getLabel() is safe metadata the caretaker may display.
 */
public final class EditorMemento {
    private final String content;
    private final String label;

    public EditorMemento(String content, String label) {
        this.content = content;
        this.label = label;
    }

    // Read by the Originator to restore state. In a stricter design this
    // would be package-private / nested so ONLY TextEditor could call it.
    public String getContent() {
        return content;
    }

    // Safe metadata for the caretaker to show, without exposing the state.
    public String getLabel() {
        return label;
    }
}
