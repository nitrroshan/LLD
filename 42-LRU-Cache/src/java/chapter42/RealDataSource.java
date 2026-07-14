package chapter42;

/**
 * The slow backing store (a simulated database). Prints when it's hit so the
 * proxy's caching is visible.
 */
public class RealDataSource implements DataSource<Integer, String> {
    @Override
    public String get(Integer key) {
        System.out.println("    [DB] fetching " + key);   // slow
        return "User#" + key;
    }
}
