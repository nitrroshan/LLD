package chapter21;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Memento Pattern Demo ===\n");

        TextEditor editor = new TextEditor();
        History history = new History();

        editor.type("Hello");
        history.push(editor.save("after Hello"));
        System.out.println("Content: \"" + editor.getContent() + "\"");

        editor.type(", World");
        history.push(editor.save("after World"));
        System.out.println("Content: \"" + editor.getContent() + "\"");

        editor.type("!!!");
        System.out.println("Content: \"" + editor.getContent() + "\"  (not yet saved)");

        // Undo — pop a snapshot and restore
        System.out.println("\nUndo:");
        editor.restore(history.pop());
        System.out.println("Content: \"" + editor.getContent() + "\"");

        System.out.println("\nUndo again:");
        editor.restore(history.pop());
        System.out.println("Content: \"" + editor.getContent() + "\"");

        System.out.println("\nThe editor's content stayed private the whole time —");
        System.out.println("the History caretaker only held opaque snapshots.");
    }
}
