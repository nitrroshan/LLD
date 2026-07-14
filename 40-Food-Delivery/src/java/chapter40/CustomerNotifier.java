package chapter40;

public class CustomerNotifier implements OrderObserver {
    @Override
    public void onStatusChanged(Order order, String status) {
        System.out.println("    [Customer " + order.customer().name() + "] order is now " + status);
    }
}
