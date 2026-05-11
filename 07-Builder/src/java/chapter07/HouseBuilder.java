package chapter07;

public class HouseBuilder {
    private int rooms = 1;
    private int floors = 1;
    private boolean hasGarage = false;
    private boolean hasPool = false;
    private boolean hasGarden = false;
    private String roofType = "shingle";

    public HouseBuilder rooms(int count) {
        this.rooms = count;
        return this;
    }

    public HouseBuilder floors(int count) {
        this.floors = count;
        return this;
    }

    public HouseBuilder garage() {
        this.hasGarage = true;
        return this;
    }

    public HouseBuilder pool() {
        this.hasPool = true;
        return this;
    }

    public HouseBuilder garden() {
        this.hasGarden = true;
        return this;
    }

    public HouseBuilder roofType(String type) {
        this.roofType = type;
        return this;
    }

    public House build() {
        if (rooms < 1) {
            throw new IllegalStateException("House must have at least 1 room");
        }
        if (floors < 1) {
            throw new IllegalStateException("House must have at least 1 floor");
        }
        return new House(rooms, floors, hasGarage, hasPool, hasGarden, roofType);
    }
}
