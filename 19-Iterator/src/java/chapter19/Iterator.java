package chapter19;

/**
 * Iterator — declares sequential access. hasNext() reports whether more
 * elements remain; next() returns the current one and advances the cursor.
 */
public interface Iterator<T> {
    boolean hasNext();
    T next();
}
