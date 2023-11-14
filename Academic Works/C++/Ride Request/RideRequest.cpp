/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Sep 16 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "RideRequest.h"
#include <string>
//intialization of global variables
double g_taxrate = 0.0;
double g_discount = 0.0;

namespace sdds {
	std::istream& RideRequest::read(std::istream& is) {
		if (!is.good()) {
			throw std::runtime_error("Error reading data from input stream.");
		} // added after my prof's feedback

		is.getline(m_customer, 10, ',');
		std::string input;
		std::getline(is, input, ',');
		delete[] m_extraDetail; //Deallocate the previous memory for safety
		m_extraDetail = new char[input.length() + 1]; //Allocate dynamic memory
		strcpy(m_extraDetail, input.c_str());//Change input to C-style null0terminated string
		is >> m_price;
		is.ignore();
		char discountStatus;
		is >> discountStatus;
		m_discount = (discountStatus == 'Y');
		is.ignore();
		return is;
	}

	void RideRequest::display() const {
		static int counter = 1; //Has the lifetime of the program
		double priceWithTax = m_price * (1 + g_taxrate);
		double priceWithDiscount = priceWithTax - g_discount;
		if (m_customer[0] != '\0') {
			std::cout.width(2);
			std::cout << std::left << counter << ". ";
			std::cout.width(10);
			std::cout << std::left << m_customer << "|";
			std::cout.width(25);
			std::cout << std::left << m_extraDetail << "|";
			std::cout.width(12);
			std::cout.setf(std::ios::fixed);
			std::cout.precision(2);
			std::cout << std::left << priceWithTax << "|";
			if (m_discount) {
				std::cout.width(13);
				std::cout << std::right << priceWithDiscount;
			}
			std::cout << std::endl;
		}
		else {
			std::cout << counter << ". No Ride Request" << std::endl;
		}
		counter++; //No death when it goes out of scope
	}

}