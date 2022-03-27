
#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H

#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Vehicle.h"
using namespace std;

namespace sdds {

	const int MAX_LOT_SIZE = 100;

	class Parking {
		char* filename;
		Menu parkingMenu;
		Menu VehicleMenu;
		int parked;
		int park_capacity;
		Vehicle* m_parkingSpots[MAX_LOT_SIZE];


		bool isEmpty();
		void Parkingstatus();
		void ParkVehicle();
		void ReturnVehicle();
		void ListParkedVehicles();
		bool closeParking();
		bool ExitParkingApp();
		bool loadDataFile();
		void saveDataFile();
		void setEmpty();


	public:
		Parking(const char* datafile, int NoOfSpots);
		int run();
		~Parking();

	};

}

#endif 