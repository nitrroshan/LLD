#pragma once
#include "HouseBuilder.h"

class HouseDirector {
public:
    House build_luxury_house(HouseBuilder builder) {
        return builder.rooms(6).floors(3).garage().pool()
                      .garden().roof_type("slate").build();
    }

    House build_simple_house(HouseBuilder builder) {
        return builder.rooms(2).floors(1).roof_type("shingle").build();
    }

    House build_family_house(HouseBuilder builder) {
        return builder.rooms(4).floors(2).garage().garden()
                      .roof_type("tile").build();
    }
};
