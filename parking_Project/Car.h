
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           25/07/2020
//I have done all the coding by myself and only copied the code that my professor provided to complete this program
#ifndef SDDS_CAR_H__

#define SDDS_CAR_H__



#include <iostream>

#include "Vehicle.h"



namespace sdds {

	class Car : public Vehicle {

		bool c_wash;

	  public:

		Car(); 

		Car(const char* plt , const char* make_model );

		Car(const Car& ) = delete;

		bool getCarWash()const;
		
		istream& read(istream&);
		
		ostream& write(ostream&)const;
		
	};

}

#endif