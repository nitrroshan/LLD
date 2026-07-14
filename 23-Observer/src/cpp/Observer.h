#pragma once

// Observer — the update interface all subscribers implement (push model).
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(float temperature) = 0;
};
