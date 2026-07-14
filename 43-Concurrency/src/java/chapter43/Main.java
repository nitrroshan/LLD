package chapter43;

/**
 * Runnable demos:
 *  1) A counter race — unsafe (loses updates) vs synchronized vs atomic.
 *  2) Producer-Consumer over a bounded blocking buffer.
 *  3) A read/write-locked cache under concurrent readers + a writer.
 */
public class Main {
    private static final int THREADS = 4;
    private static final int PER_THREAD = 100_000;
    private static final int EXPECTED = THREADS * PER_THREAD;

    public static void main(String[] args) throws InterruptedException {
        System.out.println("=== Concurrency Demo (Java) ===\n");

        // 1) Race demo.
        System.out.println("Scenario 1: counter race (" + THREADS + " threads x " + PER_THREAD + ")");
        Counters.UnsafeCounter unsafe = new Counters.UnsafeCounter();
        Counters.SynchronizedCounter sync = new Counters.SynchronizedCounter();
        Counters.AtomicCounter atomic = new Counters.AtomicCounter();
        runIncrements(unsafe::increment);
        runIncrements(sync::increment);
        runIncrements(atomic::increment);
        System.out.println("  expected     = " + EXPECTED);
        System.out.println("  unsafe       = " + unsafe.get() + "  (usually < expected — lost updates)");
        System.out.println("  synchronized = " + sync.get());
        System.out.println("  atomic       = " + atomic.get());

        // 2) Producer-Consumer.
        System.out.println("\nScenario 2: producer-consumer (bounded buffer)");
        producerConsumerDemo();

        // 3) Read/write cache.
        System.out.println("\nScenario 3: read/write-locked cache");
        readWriteCacheDemo();
    }

    private static void runIncrements(Runnable increment) throws InterruptedException {
        Thread[] threads = new Thread[THREADS];
        for (int i = 0; i < THREADS; i++) {
            threads[i] = new Thread(() -> {
                for (int j = 0; j < PER_THREAD; j++) increment.run();
            });
        }
        for (Thread t : threads) t.start();
        for (Thread t : threads) t.join();
    }

    private static void producerConsumerDemo() throws InterruptedException {
        BlockingBuffer<Integer> buffer = new BlockingBuffer<>(5);
        int items = 10;

        Thread producer = new Thread(() -> {
            try {
                for (int i = 1; i <= items; i++) {
                    buffer.put(i);
                    System.out.println("  produced " + i);
                }
            } catch (InterruptedException e) { Thread.currentThread().interrupt(); }
        });

        Thread consumer = new Thread(() -> {
            try {
                for (int i = 0; i < items; i++) {
                    int v = buffer.take();
                    System.out.println("    consumed " + v);
                }
            } catch (InterruptedException e) { Thread.currentThread().interrupt(); }
        });

        producer.start();
        consumer.start();
        producer.join();
        consumer.join();
    }

    private static void readWriteCacheDemo() throws InterruptedException {
        ReadWriteCache<Integer, String> cache = new ReadWriteCache<>();
        for (int i = 0; i < 5; i++) cache.put(i, "v" + i);

        Thread writer = new Thread(() -> {
            for (int i = 5; i < 10; i++) cache.put(i, "v" + i);
        });
        Thread[] readers = new Thread[3];
        for (int r = 0; r < readers.length; r++) {
            readers[r] = new Thread(() -> {
                for (int i = 0; i < 5; i++) cache.get(i);   // many readers concurrently
            });
        }

        writer.start();
        for (Thread t : readers) t.start();
        writer.join();
        for (Thread t : readers) t.join();
        System.out.println("  cache size after concurrent access = " + cache.size());
    }
}
