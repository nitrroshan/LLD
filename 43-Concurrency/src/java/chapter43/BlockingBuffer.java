package chapter43;

import java.util.LinkedList;
import java.util.Queue;

/**
 * A bounded blocking queue built by hand with wait/notify — the heart of the
 * Producer-Consumer pattern. put() blocks when full; take() blocks when empty.
 * (In real code, prefer java.util.concurrent.ArrayBlockingQueue.)
 */
public class BlockingBuffer<T> {
    private final Queue<T> queue = new LinkedList<>();
    private final int capacity;

    public BlockingBuffer(int capacity) {
        this.capacity = capacity;
    }

    public synchronized void put(T item) throws InterruptedException {
        while (queue.size() == capacity) {
            wait();                 // release the lock and sleep until notified
        }
        queue.add(item);
        notifyAll();                // wake consumers waiting on empty
    }

    public synchronized T take() throws InterruptedException {
        while (queue.isEmpty()) {
            wait();
        }
        T item = queue.poll();
        notifyAll();                // wake producers waiting on full
        return item;
    }
}
