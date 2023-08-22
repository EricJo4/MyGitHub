/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: July 16 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Truck.h"
#include "cstring.h"

namespace sdds {
	//constructors
	Truck::Truck() {
		MotorVehicle();
		m_capacity = 0.0;
		m_currentCargo = 0.0;
	}
	Truck::Truck(const char* number, int year, double capacity, const char* address): MotorVehicle(number, year) {
		MotorVehicle(number, year);
		m_capacity = capacity;
		m_currentCargo = 0.0;
		moveTo(address);
	}

	/*
	a mutator that adds to the attribute that stores the current cargo load the weight specified as a parameter.Do not exceed the capacity!
	If the current load has been changed, return true, otherwise return false.
	*/
	bool Truck::addCargo(double cargo) {
		if (m_currentCargo + cargo <= m_capacity) {
			m_currentCargo += cargo;
			return true;
		}
		else if (m_currentCargo != m_capacity) {
			m_currentCargo = m_capacity;
			return true;
		}
		return false;
	}
	
	//a mutator that unloads current cargo (sets the attribute to 0). If the current load has been changed, return true, otherwise, return false.
	bool Truck::unloadCargo() {
		if (m_currentCargo > 0) {
			m_currentCargo = 0;
			return true;
		}
		return false;
	}
	//a query that inserts into os the content of the object in the format
	std::ostream& Truck::write(std::ostream& os)const {
		return MotorVehicle::write(os) << " | " << m_currentCargo << "/" << m_capacity;
	}
	//a mutator that reads from the stream in the data for the current object
	std::istream& Truck::read(std::istream& in) {
		MotorVehicle::read(in);
		std::cout << "Capacity: ";
		in >> m_capacity;
		std::cout << "Cargo: ";
		in >> m_currentCargo;
		return in;
	}
	//insertion operator to insert a Truck into a stream.
	std::ostream& operator<<(std::ostream& os, const Truck& truck) {
		return truck.write(os);
	}
	//extraction operator to extract a Truck into a stream.
	std::istream& operator>>(std::istream& in, Truck& truck) {
		return truck.read(in);
	}

}