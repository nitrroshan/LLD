package chapter40;

public class RestaurantNotifier implements OrderObserver {
    @Override
    public void onStatusChanged(Order order, String status) {
        System.out.println("    [Restaurant " + order.restaurant().name() + "] order is now " + status);
    }
}
