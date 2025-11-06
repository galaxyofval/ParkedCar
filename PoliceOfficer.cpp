#include "PoliceOfficer.h"

PoliceOfficer::PoliceOfficer(string n, int badge)
    : name(n), badgeNumber(badge) {}

ParkingTicket* PoliceOfficer::inspectCar(const ParkedCar& car, const ParkingMeter& meter) {
    if (car.getMinutesParked() > meter.getPurchasedMinutes()) {
        int illegalMinutes = car.getMinutesParked() - meter.getPurchasedMinutes();
        return new ParkingTicket(car, name, badgeNumber, illegalMinutes);
    }
    return nullptr;
}
