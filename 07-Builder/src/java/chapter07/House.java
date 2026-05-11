package chapter07;

public class House {
    private final int rooms;
    private final int floors;
    private final boolean hasGarage;
    private final boolean hasPool;
    private final boolean hasGarden;
    private final String roofType;

    // Private constructor — only Builder can create a House
    House(int rooms, int floors, boolean hasGarage, boolean hasPool,
          boolean hasGarden, String roofType) {
        this.rooms = rooms;
        this.floors = floors;
        this.hasGarage = hasGarage;
        this.hasPool = hasPool;
        this.hasGarden = hasGarden;
        this.roofType = roofType;
    }

    public int getRooms() { return rooms; }
    public int getFloors() { return floors; }
    public boolean hasGarage() { return hasGarage; }
    public boolean hasPool() { return hasPool; }
    public boolean hasGarden() { return hasGarden; }
    public String getRoofType() { return roofType; }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("House [")
          .append(rooms).append(" rooms, ")
          .append(floors).append(" floors, ")
          .append("roof=").append(roofType);
        if (hasGarage) sb.append(", garage");
        if (hasPool) sb.append(", pool");
        if (hasGarden) sb.append(", garden");
        sb.append("]");
        return sb.toString();
    }
}
