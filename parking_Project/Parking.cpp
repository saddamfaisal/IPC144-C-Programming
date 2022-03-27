

#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"
#include "Car.h"
#include "Motorcycle.h"
#include <fstream>
#include <iomanip>

using namespace std;

namespace sdds {


	Parking::Parking(const char* title, int noOfSpots) {

		if (noOfSpots < 10 || noOfSpots > MAX_LOT_SIZE) {
			park_capacity = 0;
		}
		else {
			park_capacity = noOfSpots;
		}
		parked = -1;

		for (int i = 0; i < MAX_LOT_SIZE; i++) {
			m_parkingSpots[i] = nullptr;
		}

		if (title == nullptr || strlen(title) == 0) {
			filename = nullptr;
		}
		else {
			filename = new char[strlen(title) + 1];
			strcpy(filename, title);
		}

		if (loadDataFile()) {

			parkingMenu.setTitle("Parking Menu, select an action:");
			parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
			VehicleMenu.setTitle("Select type of the vehicle:");
			VehicleMenu.setIdentation(1);
			VehicleMenu << "Car" << "Motorcycle" << "Cancel";
		}
		else {
			cout << "Error in data file" << endl;
		}
	}

	bool Parking::isEmpty() {
		if (filename == nullptr)
			return true;
		return false;
	}

	void Parking::Parkingstatus() {
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout << left << setw(4) << (park_capacity - parked) << " *****" << endl;
	}


	void Parking::ParkVehicle() {
		if (parked == park_capacity) {
			cout << "Parking is full" << endl;
		}
		else {
			int i = 0;
			int select;
			select = VehicleMenu.run();
			switch (select) {
			case 1:
				while (m_parkingSpots[i] != nullptr) {
					i++;
				}
				m_parkingSpots[i] = new Car;
				cin >> *m_parkingSpots[i];
				parked++;
				m_parkingSpots[i]->setParkingSpot(i + 1);
				cout << "Parking Ticket" << endl;
				cout << *m_parkingSpots[i] << endl;
				break;
			case 2:
				while (m_parkingSpots[i] != nullptr) {
					i++;
				}
				m_parkingSpots[i] = new Motorcycle;
				cin >> *m_parkingSpots[i];
				parked++;
				m_parkingSpots[i]->setParkingSpot(i + 1);
				cout << "Parking Ticket" << endl;
				cout << *m_parkingSpots[i] << endl;
				break;
			case 3:
				cout << "Parking cancelled" << endl;
				break;
			default:
				cout << "Invalid Response";
			}
		}
	}


	void Parking::ReturnVehicle() {
		char lic[10];
		bool done = false;
		cout << "Return Vehicle" << endl;

		cout << "Enter Licence Plate Number: ";
		cin.getline(lic, 11);
		cin.clear();

		while (strlen(lic) > 8 || strlen(lic) < 1) {
			cout << "Invalid License Plate, try again: ";
			cin.getline(lic, 11);
			cin.clear();
		}
		cout << endl;
		for (int i = 0; i < parked; i++) {
			if (m_parkingSpots[i] != nullptr) {
				if (*m_parkingSpots[i] == lic) {
					cout << "Returning: " << endl << *m_parkingSpots[i] << endl;
					m_parkingSpots[i]->~Vehicle();
					m_parkingSpots[i] = nullptr;
					parked--;
					done = true;
					break;
				}
			}
		}

		if (!done) {
			cout << "License plate " << lic << " Not found" << endl;
		}
	}

	void Parking::ListParkedVehicles() {
		for (int i = 0; i < park_capacity; i++) {
			if (m_parkingSpots[i] != nullptr) {
				cout << *m_parkingSpots[i] << "-------------------------------" << endl;
			}
		}
	}

	bool Parking::closeParking() {
		bool allEmpty = true;

		for (int i = 0; i < park_capacity; i++) {
			if (m_parkingSpots[i] != nullptr) {
				allEmpty = false;
			}
		}
		char ch[10];
		bool flag = false;
		bool result = false;
		if (!allEmpty) {
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			cin >> ch;
			cin.clear();

			while (!flag) {
				if (!strcmp(ch, "y")) {
					cout << "Closing Parking" << endl << endl;
					for (int i = 0; i < park_capacity; i++) {
						if (m_parkingSpots[i] != nullptr) {
							cout << "Towing request" << endl;
							cout << "*********************" << endl;

							cout << *m_parkingSpots[i];
							if (i < parked - 0) { cout << endl; }
							m_parkingSpots[i]->~Vehicle();
							m_parkingSpots[i] = nullptr;
						}
					}

					result = false;

					flag = true;
				}
				else if (!strcmp(ch, "n")) {
					cout << "Aborted!" << endl;
					flag = true;
					result = true;
				}
				else {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					cin >> ch;
					cin.ignore(2000, '\n');
				}
			}
		}
		return result;
	}


	bool Parking::ExitParkingApp() {

		char ch[10];
		bool flag = false;
		bool result = false;
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		cin >> ch;
		cin.ignore(2000, '\n');
		while (!flag) {
			if (!strcmp(ch, "y") || !strcmp(ch, "Y")) {
				cout << "Exiting program!" << endl;
				result = true;
				flag = true;
			}
			else if (!strcmp(ch, "n")) {
				flag = true;
				result = false;
			}
			else {
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin >> ch;
				cin.ignore(2000, '\n');
			}
		}
		return result;
	}


	bool Parking::loadDataFile() {
		bool position = false;
		if (!isEmpty()) {
			ifstream datafile(filename);
			if (datafile.is_open() || datafile.good()) {
				position = true;
				for (int i = 0; i < park_capacity; i++) {
					char read = '\0';
					datafile >> read;
					datafile.ignore(1, ',');
					if (read == 'C') {
						m_parkingSpots[i] = new Car();
						m_parkingSpots[i]->setCsv(true);
						datafile >> *m_parkingSpots[i];
						parked++;
						m_parkingSpots[i]->setCsv(false);
					}
					else if (read == 'M') {
						m_parkingSpots[i] = new Motorcycle();
						m_parkingSpots[i]->setCsv(true);
						datafile >> *m_parkingSpots[i];
						parked++;
						m_parkingSpots[i]->setCsv(false);
					}
				}
			}
			else {
				position = true;
			}
			datafile.close();
		}
		return position;
	}



	void Parking::saveDataFile() {
		if (!isEmpty()) {
			ofstream output(filename);
			if (output) {
				for (int i = 0; i < park_capacity; i++) {
					if (m_parkingSpots[i] != nullptr) {
						m_parkingSpots[i]->setCsv(true);
						m_parkingSpots[i]->write(output);
					}
				}
			}
		}
	}


	int Parking::run() {

		bool flag = true;
		if (!isEmpty()) {
			int select;
			while (flag) {
				Parkingstatus();
				select = parkingMenu.run();
				switch (select) {
				case 1:

					ParkVehicle();
					break;
				case 2:
					ReturnVehicle();
					break;
				case 3:

					ListParkedVehicles();
					break;
				case 4:

					flag = closeParking();
					if (!flag) cin.ignore(2000, '\n');

					break;
				case 5:

					bool exitornot;
					exitornot = ExitParkingApp();
					flag = !exitornot;


					break;
				default:
					cout << "something good";
				}
			}
		}
		return flag;
	}


	void Parking::setEmpty() {
		delete[] filename;
		filename = nullptr;
		for (int i = 0; i < park_capacity; i++)
			delete m_parkingSpots[i];
	}

	Parking::~Parking() {
		delete[] filename;
		filename = nullptr;
	}
}