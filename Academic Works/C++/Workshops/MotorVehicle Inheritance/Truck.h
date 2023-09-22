/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: July 16 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TRUCK_H_
#define SDDS_TRUCK_H_
#include "MotorVehicle.h"

namespace sdds {
	class Truck : public MotorVehicle {
		double m_capacity;
		double m_currentCargo;
	public:
		Truck();
		Truck(const char* number, int year, double capacity, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Truck& truck);
	std::istream& operator>>(std::istream& in, Truck& truck);
}


#endif // SDDS_TRUCK_H_