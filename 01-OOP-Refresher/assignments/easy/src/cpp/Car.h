#pragma once
#include "Vehicle.h"

// TODO: Inherit from Vehicle (public)
// TODO: Add private field: numDoors (int)
// TODO: Constructor that takes brand, speed, numDoors (call base constructor)
// TODO: Getter for numDoors
// TODO: Implement displayInfo() const override
//       → print: "Car: <brand> | Speed: <speed> km/h | Doors: <numDoors>"

class Car : public Vehicle {

    int numDoors;
    public:
    Car(string brand,int speed,int numDoors){
        super(brand,speed);
        this->numDoors=numDoors;
    }

    int getNumDoors() return numDoors;

    void displayInfo() const{
        printf("Car: %s | Speed: %d km/h | Doors: %d", brand,speed,numDoors);
    }

};
