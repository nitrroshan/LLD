package chapter05;

public class Airplane implements Transport {
    @Override
    public void deliver() {
        System.out.println("Delivering by air in a cargo airplane.");
    }

    @Override
    public String getName() { return "Airplane"; }
}
