#pragma once

class Visitor;  // forward declaration

// Element — declares accept(visitor).
class Expression {
public:
    virtual ~Expression() = default;
    virtual void accept(Visitor& visitor) = 0;
};
