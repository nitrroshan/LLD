#include <iostream>
#include "EditorMemento.h"
#include "TextEditor.h"
#include "History.h"

int main() {
    std::cout << "=== Memento Pattern Demo (C++) ===\n\n";

    TextEditor editor;
    History history;

    editor.type("Hello");
    history.push(editor.save("after Hello"));
    std::cout << "Content: \"" << editor.content() << "\"\n";

    editor.type(", World");
    history.push(editor.save("after World"));
    std::cout << "Content: \"" << editor.content() << "\"\n";

    editor.type("!!!");
    std::cout << "Content: \"" << editor.content() << "\"  (not yet saved)\n";

    std::cout << "\nUndo:\n";
    editor.restore(history.pop());
    std::cout << "Content: \"" << editor.content() << "\"\n";

    std::cout << "\nUndo again:\n";
    editor.restore(history.pop());
    std::cout << "Content: \"" << editor.content() << "\"\n";

    std::cout << "\nThe editor's content stayed private the whole time \u2014\n";
    std::cout << "only TextEditor (a friend) could read the snapshots.\n";

    return 0;
}
