package chapter43;

import java.util.concurrent.atomic.AtomicInteger;

/**
 * Three counters for the race demo: unsafe (plain int++), synchronized (lock),
 * and atomic (lock-free RMW). Only the unsafe one loses updates under threads.
 */
public class Counters {

    /** BUG: count++ is read-modify-write, not atomic. */
    static class UnsafeCounter {
        private int count = 0;
        public void increment() { count++; }
        public int get() { return count; }
    }

    /** Correct: only one thread in the critical section at a time. */
    static class SynchronizedCounter {
        private int count = 0;
        public synchronized void increment() { count++; }
        public synchronized int get() { return count; }
    }

    /** Correct and lock-free: atomic read-modify-write. */
    static class AtomicCounter {
        private final AtomicInteger count = new AtomicInteger(0);
        public void increment() { count.incrementAndGet(); }
        public int get() { return count.get(); }
    }
}
