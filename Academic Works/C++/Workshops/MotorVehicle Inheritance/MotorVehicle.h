/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: July 16 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H
#define MAX_LICENCE_NUMBER_LENGTH 9
#define MAX_ADDRESS_LENGTH 64
#include <iostream>

namespace sdds {
	class MotorVehicle {
		char m_plateNumber[MAX_LICENCE_NUMBER_LENGTH];
		char m_address[MAX_ADDRESS_LENGTH];
		int m_yearBuilt;
	public:
		MotorVehicle();
		MotorVehicle(const char* number, int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};

	std::ostream& operator << (std::ostream& os, const MotorVehicle& motorVehicle);
	std::istream& operator >> (std::istream& in, MotorVehicle& mootrVehicle);
}

#endif // SDDS_MOTORVEHICLE_H