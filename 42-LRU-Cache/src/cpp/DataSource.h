#pragma once

// The thing being cached — a source of values by key.
template <class K, class V>
class DataSource {
public:
    virtual ~DataSource() = default;
    virtual V get(const K& key) = 0;
};
