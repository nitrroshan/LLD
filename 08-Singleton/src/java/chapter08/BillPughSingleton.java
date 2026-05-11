package chapter08;

/**
 * Bill Pugh Singleton — recommended Java approach.
 * Uses a static inner class for lazy, thread-safe initialization.
 * The Holder class is not loaded until getInstance() is called.
 */
public class BillPughSingleton {

    private BillPughSingleton() {
        if (Holder.INSTANCE != null) {
            throw new RuntimeException("Use getInstance() — cannot create via reflection");
        }
    }

    private static class Holder {
        private static final BillPughSingleton INSTANCE = new BillPughSingleton();
    }

    public static BillPughSingleton getInstance() {
        return Holder.INSTANCE;
    }

    public void doSomething() {
        System.out.println("[BillPughSingleton] Working... hashCode=" + hashCode());
    }
}
