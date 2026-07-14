#pragma once
#include <string>
#include "EditorMemento.h"

// Originator — snapshots and restores its own private state.
class TextEditor {
    std::string content_;

public:
    void type(const std::string& text) {
        content_ += text;
    }

    const std::string& content() const {
        return content_;
    }

    // Snapshot current state into a memento (TextEditor is a friend, so it
    // may use the memento's private constructor).
    EditorMemento save(const std::string& label) const {
        return EditorMemento(content_, label);
    }

    // Restore from a memento (friend access lets us read its private state).
    void restore(const EditorMemento& memento) {
        content_ = memento.content();
    }
};
