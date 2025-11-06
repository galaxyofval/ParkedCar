#include "ParkedCar.h"

ParkedCar::ParkedCar(string mk, string mdl, string clr, string plate, int mins)
    : make(mk), model(mdl), color(clr), licensePlate(plate), minutesParked(mins) {}

int ParkedCar::getMinutesParked() const { return minutesParked; }
string ParkedCar::getMake() const { return make; }
string ParkedCar::getModel() const { return model; }
string ParkedCar::getColor() const { return color; }
string ParkedCar::getLicense() const { return licensePlate; }
