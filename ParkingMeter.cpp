#include "ParkingMeter.h"

ParkingMeter::ParkingMeter(int mins) : purchasedMinutes(mins) {}
int ParkingMeter::getPurchasedMinutes() const { return purchasedMinutes; }
