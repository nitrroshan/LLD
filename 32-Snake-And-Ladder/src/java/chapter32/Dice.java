package chapter32;

import java.util.Random;

/**
 * A die (or dice). Configurable faces and count; seeded for reproducible demos.
 */
public class Dice {
    private final int faces;
    private final int count;
    private final Random random;

    public Dice(int faces, int count, long seed) {
        this.faces = faces;
        this.count = count;
        this.random = new Random(seed);
    }

    public int roll() {
        int total = 0;
        for (int i = 0; i < count; i++) {
            total += 1 + random.nextInt(faces);
        }
        return total;
    }

    public int maxRoll() {
        return faces * count;
    }
}
