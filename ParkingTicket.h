#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H

#include <string>
#include "ParkedCar.h"
using namespace std;

class ParkingTicket {
private:
    string make;
    string model;
    string color;
    string licensePlate;
    string officerName;
    int badgeNumber;
    double fine;

public:
    ParkingTicket(const ParkedCar& car, const string& name, int badge, int illegalMinutes);
    void display() const;
};

#endif
