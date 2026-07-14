package chapter25.centralized;

/**
 * Centralized ("context decides") variant of the State pattern.
 *
 * Instead of one class per state that transitions the machine, the STATE is a
 * plain enum and ALL transition logic lives here in the context — one switch
 * per action. Compare with the distributed version in the parent package,
 * where each State object performs its own transitions.
 *
 * Trade-offs:
 *   + Simpler for small machines; every rule is in one file, easy to read.
 *   + No state<->state references, no context back-pointer.
 *   - The context grows as states/actions multiply (the conditionals return).
 *   - Adding a state means editing every action method (weaker OCP).
 */
public class GumballMachine {

    public enum State {
        NO_QUARTER,
        HAS_QUARTER,
        SOLD,
        SOLD_OUT
    }

    private State state;
    private int count;

    public GumballMachine(int count) {
        this.count = count;
        this.state = count > 0 ? State.NO_QUARTER : State.SOLD_OUT;
    }

    public void insertQuarter() {
        switch (state) {
            case NO_QUARTER:
                System.out.println("  You inserted a quarter");
                state = State.HAS_QUARTER;
                break;
            case HAS_QUARTER:
                System.out.println("  You can't insert another quarter");
                break;
            case SOLD:
                System.out.println("  Please wait, we're already giving you a gumball");
                break;
            case SOLD_OUT:
                System.out.println("  You can't insert a quarter, the machine is sold out");
                break;
        }
    }

    public void ejectQuarter() {
        switch (state) {
            case HAS_QUARTER:
                System.out.println("  Quarter returned");
                state = State.NO_QUARTER;
                break;
            case NO_QUARTER:
                System.out.println("  You haven't inserted a quarter");
                break;
            case SOLD:
                System.out.println("  Sorry, you already turned the crank");
                break;
            case SOLD_OUT:
                System.out.println("  You can't eject, you haven't inserted a quarter yet");
                break;
        }
    }

    public void turnCrank() {
        switch (state) {
            case HAS_QUARTER:
                System.out.println("  You turned the crank...");
                state = State.SOLD;
                dispense();
                break;
            case NO_QUARTER:
                System.out.println("  You turned, but there's no quarter");
                break;
            case SOLD:
                System.out.println("  Turning twice doesn't get you another gumball");
                break;
            case SOLD_OUT:
                System.out.println("  You turned, but there are no gumballs");
                break;
        }
    }

    // A count-dependent transition — note this is exactly the kind of rule a
    // pure static transition TABLE cannot express, so it lives in code here.
    private void dispense() {
        if (state != State.SOLD) {
            return;
        }
        if (count > 0) {
            System.out.println("  A gumball rolls out...");
            count--;
        }
        if (count > 0) {
            state = State.NO_QUARTER;
        } else {
            System.out.println("  Oops, out of gumballs!");
            state = State.SOLD_OUT;
        }
    }

    public String status() {
        return "[state=" + state + ", gumballs=" + count + "]";
    }
}
