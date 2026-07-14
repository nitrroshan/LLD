#pragma once
#include <iostream>

// Abstract base using the Non-Virtual Interface (NVI) idiom:
// prepare_recipe() is PUBLIC and NON-virtual (the fixed skeleton), while the
// varying steps are private/protected virtual methods subclasses override.
class CaffeineBeverage {
public:
    virtual ~CaffeineBeverage() = default;

    // Template method — the fixed skeleton. Non-virtual, so it can't be overridden.
    void prepare_recipe() {
        boil_water();
        brew();
        pour_in_cup();
        if (wants_condiments()) {
            add_condiments();
        }
    }

private:
    // Invariant steps — shared by all beverages.
    void boil_water() { std::cout << "  Boiling water\n"; }
    void pour_in_cup() { std::cout << "  Pouring into cup\n"; }

protected:
    // Varying steps — subclasses must supply these.
    virtual void brew() = 0;
    virtual void add_condiments() = 0;

    // Hook — default a subclass may override.
    virtual bool wants_condiments() { return true; }
};
