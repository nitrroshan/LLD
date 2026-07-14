package chapter45;

/** Time as an injected abstraction — deterministic in tests (no wall clock). */
public interface Clock {
    long now();
}
