#pragma once
#include "Song.h"

// Iterator — declares sequential access. has_next() reports whether more
// elements remain; next() returns the current one and advances the cursor.
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual bool has_next() const = 0;
    virtual Song next() = 0;
};
