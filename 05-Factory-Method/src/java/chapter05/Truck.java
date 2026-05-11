package chapter05;

public class Truck implements Transport {
    @Override
    public void deliver() {
        System.out.println("Delivering by land in a truck.");
    }

    @Override
    public String getName() { return "Truck"; }
}
