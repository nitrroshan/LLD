package chapter41;

/**
 * Simulated file appender — prints with a [file] tag instead of real I/O.
 * (Log rotation would live here, hidden from the handler and logger.)
 */
public class FileAppender implements Appender {
    private final String fileName;

    public FileAppender(String fileName) {
        this.fileName = fileName;
    }

    @Override
    public void append(String line) {
        System.out.println("    [file:" + fileName + "] " + line);
    }
}
