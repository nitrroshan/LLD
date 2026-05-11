package chapter05;

public class Ship implements Transport {
    @Override
    public void deliver() {
        System.out.println("Delivering by sea in a container ship.");
    }

    @Override
    public String getName() { return "Ship"; }
}
