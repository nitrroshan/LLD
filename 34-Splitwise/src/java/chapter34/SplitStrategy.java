package chapter34;

import java.util.List;

/**
 * Strategy — turns a total into per-participant splits.
 */
public interface SplitStrategy {
    List<Split> calculateSplits(double total, List<User> participants);
}
