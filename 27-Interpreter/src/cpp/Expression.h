#pragma once

class Context;  // forward declaration

// AbstractExpression — every grammar rule implements interpret(context).
class Expression {
public:
    virtual ~Expression() = default;
    virtual bool interpret(const Context& context) const = 0;
};
