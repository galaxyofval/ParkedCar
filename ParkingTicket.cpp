#include "ParkingTicket.h"
#include <iostream>
#include <cmath>
using namespace std;

ParkingTicket::ParkingTicket(const ParkedCar& car, const string& name, int badge, int illegalMinutes) {
    make = car.getMake();
    model = car.getModel();
    color = car.getColor();
    licensePlate = car.getLicense();
    officerName = name;
    badgeNumber = badge;

    int hoursOver = ceil(illegalMinutes / 60.0);
    fine = 25.0 + 10.0 * (hoursOver - 1);
}

void ParkingTicket::display() const {
    cout << "*** Parking Ticket ***\n";
    cout << "Officer " << officerName << " (Badge " << badgeNumber << ")\n";
    cout << "Vehicle License: " << licensePlate << "\n";
    cout << "Make: " << make << " | Model: " << model << " | Color: " << color << "\n";
    cout << "Fine: $" << fine << "\n\n";
}
