package chapter25;

/**
 * Context — holds the current state and delegates every action to it. It also
 * owns the shared data (the gumball count) and provides setState for transitions.
 */
public class GumballMachine {
    private final State noQuarterState;
    private final State hasQuarterState;
    private final State soldState;
    private final State soldOutState;

    private State current;
    private int count;

    public GumballMachine(int count) {
        this.count = count;
        noQuarterState = new NoQuarterState(this);
        hasQuarterState = new HasQuarterState(this);
        soldState = new SoldState(this);
        soldOutState = new SoldOutState(this);
        current = count > 0 ? noQuarterState : soldOutState;
    }

    // Actions simply delegate to the current state.
    public void insertQuarter() { current.insertQuarter(); }
    public void ejectQuarter()  { current.ejectQuarter(); }
    public void turnCrank() {
        current.turnCrank();
        current.dispense();
    }

    void setState(State state) { this.current = state; }

    void releaseBall() {
        if (count > 0) {
            System.out.println("  A gumball rolls out...");
            count--;
        }
    }

    int getCount() { return count; }

    State getNoQuarterState() { return noQuarterState; }
    State getHasQuarterState() { return hasQuarterState; }
    State getSoldState()       { return soldState; }
    State getSoldOutState()    { return soldOutState; }

    public String status() {
        return "[state=" + current.name() + ", gumballs=" + count + "]";
    }
}
