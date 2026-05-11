package chapter08;

/**
 * Eager Singleton — instance created at class loading time.
 * Simplest approach. Thread-safe by JVM guarantee.
 */
public class EagerSingleton {
    private static final EagerSingleton INSTANCE = new EagerSingleton();

    private EagerSingleton() {
        // Reflection prevention
        if (INSTANCE != null) {
            throw new RuntimeException("Use getInstance() — cannot create via reflection");
        }
    }

    public static EagerSingleton getInstance() {
        return INSTANCE;
    }

    public void doSomething() {
        System.out.println("[EagerSingleton] Working... hashCode=" + hashCode());
    }
}
