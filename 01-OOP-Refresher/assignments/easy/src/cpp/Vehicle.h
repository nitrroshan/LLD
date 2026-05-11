#pragma once
#include <string>
#include <iostream>

// TODO: Make this class abstract (hint: pure virtual method)
// TODO: Add private fields: brand (std::string), speed (int)
// TODO: Constructor that takes brand and speed
// TODO: Getters for both fields
// TODO: Pure virtual method: void displayInfo() const
// TODO: Concrete method: void accelerate(int amount)
//       → increases speed and prints: "<brand> accelerated! New speed: <speed> km/h"
// TODO: Virtual destructor
using namespace std;
class Vehicle {

    string brand;
    int speed;

    public:

    Vehicle(string _brand,int _speed)
    : brand = _brand, speed = _speed{

    }
    int getBrand() return brand;
    int getSpeed() return speed;

    virtual void dispalyInfo();

    void accelerate(int amount){
        speed+=amount;
        court<<brand<<" accelerated! New speed: "<<speed<<" km/h\n";
    }

    
};
