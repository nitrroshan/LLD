#pragma once
#include <string>

// Memento — an immutable snapshot. Its state is private; only the Originator
// (declared a friend) can read it. The caretaker holds it opaquely.
class EditorMemento {
    friend class TextEditor;   // only the originator may read the state

    std::string content_;
    std::string label_;

    // Private: only TextEditor (friend) constructs and reads the content.
    EditorMemento(std::string content, std::string label)
        : content_(std::move(content)), label_(std::move(label)) {}

    const std::string& content() const { return content_; }

public:
    // Safe metadata the caretaker may display without seeing the state.
    const std::string& label() const { return label_; }
};
