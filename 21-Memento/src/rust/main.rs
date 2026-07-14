mod editor_memento;
mod text_editor;
mod history;

use text_editor::TextEditor;
use history::History;

fn main() {
    println!("=== Memento Pattern Demo (Rust) ===\n");

    let mut editor = TextEditor::new();
    let mut history = History::new();

    editor.type_text("Hello");
    history.push(editor.save("after Hello"));
    println!("Content: {:?}", editor.content());

    editor.type_text(", World");
    history.push(editor.save("after World"));
    println!("Content: {:?}", editor.content());

    editor.type_text("!!!");
    println!("Content: {:?}  (not yet saved)", editor.content());

    println!("\nUndo:");
    if let Some(memento) = history.pop() {
        editor.restore(&memento);
    }
    println!("Content: {:?}", editor.content());

    println!("\nUndo again:");
    if let Some(memento) = history.pop() {
        editor.restore(&memento);
    }
    println!("Content: {:?}", editor.content());

    println!("\nThe editor's content stayed private the whole time —");
    println!("the History caretaker only held opaque snapshots.");
}
