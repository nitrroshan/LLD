package chapter28;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Singleton coordinator. Holds floors, parks/unparks vehicles, tracks active
 * tickets, and delegates fee calculation to an injected PricingStrategy.
 */
public class ParkingLot {
    private static final ParkingLot INSTANCE = new ParkingLot();

    private final List<ParkingFloor> floors = new ArrayList<>();
    private final Map<String, Ticket> activeTickets = new HashMap<>();
    private int ticketCounter = 0;

    private ParkingLot() {
    }

    public static ParkingLot getInstance() {
        return INSTANCE;
    }

    public void addFloor(ParkingFloor floor) {
        floors.add(floor);
    }

    /** Find the first suitable spot across floors, park, and issue a ticket. */
    public Ticket parkVehicle(Vehicle vehicle, long entryTime) {
        for (ParkingFloor floor : floors) {
            ParkingSpot spot = floor.findAvailableSpot(vehicle);
            if (spot != null) {
                spot.park(vehicle);
                String id = "T" + (++ticketCounter);
                Ticket ticket = new Ticket(id, vehicle, spot, entryTime);
                activeTickets.put(id, ticket);
                System.out.printf("  Parked %s (%s) at floor %d, spot %s -> ticket %s%n",
                        vehicle.getLicensePlate(), vehicle.getType(),
                        floor.getFloorNumber(), spot.getId(), id);
                return ticket;
            }
        }
        System.out.printf("  No available spot for %s (%s)%n",
                vehicle.getLicensePlate(), vehicle.getType());
        return null;
    }

    /** Compute the fee via the strategy, free the spot, and take payment. */
    public Payment unparkVehicle(Ticket ticket, long exitTime, PricingStrategy strategy) {
        double price = strategy.calculatePrice(ticket, exitTime);
        ticket.getSpot().vacate();
        activeTickets.remove(ticket.getTicketId());
        System.out.printf("  Unparked %s (ticket %s), spot %s freed%n",
                ticket.getVehicle().getLicensePlate(), ticket.getTicketId(),
                ticket.getSpot().getId());
        Payment payment = new Payment(price);
        payment.process();
        return payment;
    }

    public void displayAvailability() {
        System.out.println("  Availability:");
        for (ParkingFloor floor : floors) {
            System.out.printf("    Floor %d: %d/%d free%n",
                    floor.getFloorNumber(), floor.availableCount(), floor.totalSpots());
        }
    }
}
