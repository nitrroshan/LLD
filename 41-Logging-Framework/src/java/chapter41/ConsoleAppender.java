package chapter41;

/**
 * Writes lines to the console.
 */
public class ConsoleAppender implements Appender {
    @Override
    public void append(String line) {
        System.out.println("    [console] " + line);
    }
}
