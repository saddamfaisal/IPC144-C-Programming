

//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           08/08/2020
//I have done all the coding by myself and only copied the code that my professor provided to complete this program
#include <iostream>

#include "ReadWritable.h"



namespace sdds {

	ReadWritable::ReadWritable() {

		commaSepFlag = false;

	}



	bool ReadWritable::isCsv()const {

		return commaSepFlag;

	}



	void ReadWritable::setCsv(bool value) {

		commaSepFlag = value;

	}



	ReadWritable::~ReadWritable() {



	}


	std::ostream& operator<<(std::ostream& ost, const ReadWritable& rt)
	{

		rt.write(ost);

		return ost;
	}


	std::istream& operator>>(std::istream& ost, ReadWritable& rt) {

		rt.read(ost);

		return ost;

	}

}