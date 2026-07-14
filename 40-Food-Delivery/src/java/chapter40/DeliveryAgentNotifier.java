package chapter40;

public class DeliveryAgentNotifier implements OrderObserver {
    @Override
    public void onStatusChanged(Order order, String status) {
        String agent = order.agent() == null ? "(unassigned)" : order.agent().name();
        System.out.println("    [Agent " + agent + "] order is now " + status);
    }
}
