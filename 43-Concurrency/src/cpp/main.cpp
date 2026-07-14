#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include "Counters.h"
#include "BlockingBuffer.h"
#include "ReadWriteCache.h"

constexpr int kThreads = 4;
constexpr int kPerThread = 100000;
constexpr int kExpected = kThreads * kPerThread;

template <class Counter>
void run_increments(Counter& counter) {
    std::vector<std::thread> threads;
    for (int i = 0; i < kThreads; i++) {
        threads.emplace_back([&counter] {
            for (int j = 0; j < kPerThread; j++) counter.increment();
        });
    }
    for (auto& t : threads) t.join();
}

int main() {
    std::cout << "=== Concurrency Demo (C++) ===\n\n";

    // 1) Race demo.
    std::cout << "Scenario 1: counter race (" << kThreads << " threads x " << kPerThread << ")\n";
    UnsafeCounter unsafe;
    MutexCounter mutexc;
    AtomicCounter atomicc;
    run_increments(unsafe);
    run_increments(mutexc);
    run_increments(atomicc);
    std::cout << "  expected = " << kExpected << "\n";
    std::cout << "  unsafe   = " << unsafe.get() << "  (usually < expected - lost updates)\n";
    std::cout << "  mutex    = " << mutexc.get() << "\n";
    std::cout << "  atomic   = " << atomicc.get() << "\n";

    // 2) Producer-Consumer.
    std::cout << "\nScenario 2: producer-consumer (bounded buffer)\n";
    BlockingBuffer<int> buffer(5);
    const int items = 10;
    std::thread producer([&] {
        for (int i = 1; i <= items; i++) {
            buffer.put(i);
            std::cout << "  produced " << i << "\n";
        }
    });
    std::thread consumer([&] {
        for (int i = 0; i < items; i++) {
            int v = buffer.take();
            std::cout << "    consumed " << v << "\n";
        }
    });
    producer.join();
    consumer.join();

    // 3) Read/write cache.
    std::cout << "\nScenario 3: read/write-locked cache\n";
    ReadWriteCache<int, std::string> cache;
    for (int i = 0; i < 5; i++) cache.put(i, "v" + std::to_string(i));

    std::thread writer([&] {
        for (int i = 5; i < 10; i++) cache.put(i, "v" + std::to_string(i));
    });
    std::vector<std::thread> readers;
    for (int r = 0; r < 3; r++) {
        readers.emplace_back([&] {
            std::string v;
            for (int i = 0; i < 5; i++) cache.get(i, v);   // many readers concurrently
        });
    }
    writer.join();
    for (auto& t : readers) t.join();
    std::cout << "  cache size after concurrent access = " << cache.size() << "\n";

    return 0;
}
