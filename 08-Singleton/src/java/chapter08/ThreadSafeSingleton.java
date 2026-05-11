package chapter08;

/**
 * Thread-safe Singleton using Double-Checked Locking.
 * volatile prevents instruction reordering.
 * Locks only on first creation, then reads without synchronization.
 */
public class ThreadSafeSingleton {
    private static volatile ThreadSafeSingleton instance;

    private ThreadSafeSingleton() {
        if (instance != null) {
            throw new RuntimeException("Use getInstance() — cannot create via reflection");
        }
    }

    public static ThreadSafeSingleton getInstance() {
        if (instance == null) {                         // 1st check — no lock
            synchronized (ThreadSafeSingleton.class) {
                if (instance == null) {                 // 2nd check — with lock
                    instance = new ThreadSafeSingleton();
                }
            }
        }
        return instance;
    }

    public void doSomething() {
        System.out.println("[ThreadSafeSingleton] Working... hashCode=" + hashCode());
    }
}
