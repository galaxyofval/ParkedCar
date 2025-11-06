#ifndef PARKEDCAR_H
#define PARKEDCAR_H

#include <string>
using namespace std;

class ParkedCar {
private:
    string make;
    string model;
    string color;
    string licensePlate;
    int minutesParked;

public:
    ParkedCar(string mk, string mdl, string clr, string plate, int mins);
    int getMinutesParked() const;
    string getMake() const;
    string getModel() const;
    string getColor() const;
    string getLicense() const;
};

#endif
