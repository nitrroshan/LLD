package chapter25;

public class HasQuarterState implements State {
    private final GumballMachine machine;

    public HasQuarterState(GumballMachine machine) {
        this.machine = machine;
    }

    @Override
    public void insertQuarter() {
        System.out.println("  You can't insert another quarter");
    }

    @Override
    public void ejectQuarter() {
        System.out.println("  Quarter returned");
        machine.setState(machine.getNoQuarterState());
    }

    @Override
    public void turnCrank() {
        System.out.println("  You turned the crank...");
        machine.setState(machine.getSoldState());
    }

    @Override
    public void dispense() {
        System.out.println("  No gumball dispensed");
    }

    @Override
    public String name() {
        return "HasQuarter";
    }
}
