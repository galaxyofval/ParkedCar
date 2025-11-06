// main.cpp
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"
#include <iostream>
#include <vector>
#include <utility> // for std::pair

using namespace std;

void runScenario(const string& title,
                 const ParkedCar& car, // declaring the necessary objects needed
                 const ParkingMeter& meter,
                 PoliceOfficer& officer)
{
    cout << "\n" << title << "\n";
    cout << "Car: " << car.getMake() << " " << car.getModel()
         << " | Color: " << car.getColor()
         << " | Plate: " << car.getLicense() << "\n";
    cout << "Minutes parked: " << car.getMinutesParked()
         << " | Purchased minutes: " << meter.getPurchasedMinutes() << "\n";

    ParkingTicket* ticket = officer.inspectCar(car, meter);

    if (ticket) {
        ticket->display();
        delete ticket; // cleanup (ticket is created only on violation)
    } else {
        cout << "No violation detected.\n";
    }
}

int main() {
    // A car is parked legally.
    {
        ParkedCar car("Toyota", "Camry", "Red", "XYZ123", 30);
        ParkingMeter meter(40);
        PoliceOfficer officer("John Doe", 5678);
        runScenario("1. Car Parked Legally", car, meter, officer);
    }

    // A car is parked illegaly, but only a little bit over the time limit.
    {
        ParkedCar car("Honda", "Accord", "Blue", "ABC987", 70);
        ParkingMeter meter(60);
        PoliceOfficer officer("Jane Smith", 1234);
        runScenario("2. Illegal (<1 hour over)", car, meter, officer);
    }

    // Someone is clearly not paying attention and is multiple hours over their time.
    {
        ParkedCar car("Ford", "Mustang", "Black", "LMN456", 190);
        ParkingMeter meter(60);
        PoliceOfficer officer("James Brown", 4321);
        runScenario("3. Illegal (multiple hours over)", car, meter, officer);
    }

    // Multiple cars within a lot.
    {
        cout << "\n4. Multiple Cars in a Parking Lot\n";
        PoliceOfficer lotOfficer("Mark Smith", 2468);

        vector<pair<ParkedCar, ParkingMeter>> lot = {
            { ParkedCar("Hyundai", "Sonata", "Silver", "A12345", 120), ParkingMeter(60)  }, // over
            { ParkedCar("Chevy",   "Impala", "White",  "B67890", 45 ), ParkingMeter(60)  }, // legal
            { ParkedCar("Kia",     "Soul",   "Green",  "C13579", 61 ), ParkingMeter(60)  }, // just barely over
            { ParkedCar("BMW",     "X3",     "Black",  "D24680", 180), ParkingMeter(30)  }, // way over
            { ParkedCar("Toyota",  "RAV4",   "Blue",   "E11223", 30 ), ParkingMeter(30)  }  // right at the limit
        };

        int ticketCount = 0;
        for (size_t i = 0; i < lot.size(); ++i) {
            auto& car   = lot[i].first;
            auto& meter = lot[i].second;

            cout << "\nCar #" << (i + 1) << ": "
                 << car.getMake() << " " << car.getModel()
                 << " (" << car.getColor() << ", " << car.getLicense() << ")\n";
            cout << "Minutes parked: " << car.getMinutesParked()
                 << " | Purchased minutes: " << meter.getPurchasedMinutes() << "\n";

            ParkingTicket* ticket = lotOfficer.inspectCar(car, meter);
            if (ticket) {
                ++ticketCount;
                ticket->display();
                delete ticket;
            } else {
                cout << "No violation detected.\n";
            }
        }

        cout << "\nTotal tickets issued in parking lot: " << ticketCount << "\n";
    }
    
    return 0;
}
