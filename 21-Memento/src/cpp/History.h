#pragma once
#include <vector>
#include "EditorMemento.h"

// Caretaker — stores mementos on a stack for undo. It never reads their state.
class History {
    std::vector<EditorMemento> mementos_;

public:
    void push(const EditorMemento& memento) {
        mementos_.push_back(memento);
    }

    EditorMemento pop() {
        EditorMemento top = mementos_.back();
        mementos_.pop_back();
        return top;
    }

    bool is_empty() const {
        return mementos_.empty();
    }
};
