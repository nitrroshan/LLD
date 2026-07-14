#pragma once

// Subject — the common interface shared by the real object and the proxy.
class Image {
public:
    virtual ~Image() = default;
    virtual void display() = 0;
};
