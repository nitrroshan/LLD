package chapter08;

/**
 * Enum Singleton — bulletproof Java singleton.
 * Immune to reflection, serialization, and cloning attacks.
 */
public enum EnumSingleton {
    INSTANCE;

    private int callCount = 0;

    public void doSomething() {
        callCount++;
        System.out.println("[EnumSingleton] Call #" + callCount + " hashCode=" + hashCode());
    }

    public int getCallCount() {
        return callCount;
    }
}
