package chapter45;

/**
 * A tiny hand-rolled assert harness — stands in for JUnit so the examples run
 * anywhere. Tracks pass/fail counts and prints a result per check.
 */
public class TestSupport {
    private int passed = 0;
    private int failed = 0;

    public void assertEquals(Object expected, Object actual, String name) {
        if (expected == null ? actual == null : expected.equals(actual)) {
            pass(name);
        } else {
            fail(name + " (expected " + expected + ", got " + actual + ")");
        }
    }

    public void assertEqualsDouble(double expected, double actual, String name) {
        if (Math.abs(expected - actual) < 1e-9) {
            pass(name);
        } else {
            fail(name + " (expected " + expected + ", got " + actual + ")");
        }
    }

    public void assertTrue(boolean condition, String name) {
        if (condition) pass(name); else fail(name);
    }

    private void pass(String name) { passed++; System.out.println("  PASS  " + name); }
    private void fail(String name) { failed++; System.out.println("  FAIL  " + name); }

    public void summary() {
        System.out.println("\n  " + passed + " passed, " + failed + " failed");
    }
}
