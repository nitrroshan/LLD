package chapter21;

/**
 * Originator — the object whose state we snapshot. It creates mementos of its
 * own state and restores itself from them. Its content stays private.
 */
public class TextEditor {
    private String content = "";

    public void type(String text) {
        content += text;
    }

    public String getContent() {
        return content;
    }

    /** Snapshot the current state into a memento. */
    public EditorMemento save(String label) {
        return new EditorMemento(content, label);
    }

    /** Restore state from a previously created memento. */
    public void restore(EditorMemento memento) {
        this.content = memento.getContent();
    }
}
