package chapter07;

public class HouseDirector {

    public House buildLuxuryHouse(HouseBuilder builder) {
        return builder
                .rooms(6)
                .floors(3)
                .garage()
                .pool()
                .garden()
                .roofType("slate")
                .build();
    }

    public House buildSimpleHouse(HouseBuilder builder) {
        return builder
                .rooms(2)
                .floors(1)
                .roofType("shingle")
                .build();
    }

    public House buildFamilyHouse(HouseBuilder builder) {
        return builder
                .rooms(4)
                .floors(2)
                .garage()
                .garden()
                .roofType("tile")
                .build();
    }
}
