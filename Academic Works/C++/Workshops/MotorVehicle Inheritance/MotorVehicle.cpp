/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: July 16 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "MotorVehicle.h"
#include "cstring.h"

namespace sdds {
	//constructors
	MotorVehicle::MotorVehicle() {
		m_plateNumber[0] = '\0';
		m_address[0] = '\0';
		m_yearBuilt = 0;
	}
	MotorVehicle::MotorVehicle(const char* number, int year) {
		if (number != nullptr && number[0] != '\0' && year > 0) {
			strnCpy(m_plateNumber, number, 8);
			m_plateNumber[8] = '\0';
			m_yearBuilt = year;
			strCpy(m_address, "Factory");
		}
		
	}

	//moves the vehicle to the new address if the new address is different from the current address. Prints to the screen the message
	void MotorVehicle::moveTo(const char* address) {
		if (strCmp(m_address, address) !=0) {
			std::cout << "|";
			std::cout.width(8);
			std::cout << std::right << m_plateNumber;
			std::cout << "| |";
			std::cout.width(20);
			std::cout << m_address;
			std::cout << " ---> ";
			std::cout.width(20);
			std::cout << std::left << address << "|" << std::endl;
			strCpy(m_address, address);
		}
	}

	//a query that inserts into os the content of the object in the format
	std::ostream& MotorVehicle::write(std::ostream& os) const {
		os << "| " << m_yearBuilt << " | " << m_plateNumber << " | " << m_address;
		return os;
	}
	//a mutator that reads from the stream in the data for the current object
	std::istream& MotorVehicle::read(std::istream& in) {
		std::cout << "Built year: ";
		in >> m_yearBuilt;
		std::cout << "License plate: ";
		in.ignore();
		in.getline(m_plateNumber, 9);
		std::cout << "Current location: ";
		in.getline(m_address, 64);
		return in;
	}
	//insertion operator to insert a MotorVehicle into a stream
	std::ostream& operator << (std::ostream& os, const MotorVehicle& motorVehicle) {
		return motorVehicle.write(os);
	}
	//extraction operator to extract a MotorVehicle from a stream
	std::istream& operator >> (std::istream& in, MotorVehicle& motorVehicle) {
		return motorVehicle.read(in);
	}
}