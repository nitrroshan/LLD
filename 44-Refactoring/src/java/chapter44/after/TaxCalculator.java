package chapter44.after;

/** Single responsibility: compute tax at a configurable rate (no magic number). */
public class TaxCalculator {
    private final double rate;

    public TaxCalculator(double rate) {
        this.rate = rate;
    }

    public double tax(double amount) {
        return amount * rate;
    }
}
