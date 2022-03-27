
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           25/07/2020
//I have done all the coding by myself and only copied the code that my professor provided to complete this program
#ifndef SDDS_MOTORCYCLE_H__

#define SDDS_MOTORCYCLE_H__



#include "Vehicle.h"



namespace sdds {

	class Motorcycle : public Vehicle {

		bool 	c_side;

	public:

		Motorcycle(); 

		Motorcycle(const char* plt , const char* make_model);

		bool getSideCar() const;
		istream& read(istream&);
		ostream& write(ostream&)const;

		

	};

}

#endif