/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Sep 16 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H


#include <iostream>
#include <cstring>

extern double g_taxrate;
extern double g_discount;
namespace sdds {

	class RideRequest {
		char m_customer[10];
		char* m_extraDetail; //char array of part 1 to char pointer
		double m_price;
		bool m_discount;
	public:
		RideRequest(){
			m_customer[0] = '\0';
			m_extraDetail = nullptr;
			m_price = 0;
			m_discount = false;
		}
		//copy constructor
		RideRequest(const RideRequest& other) {
			m_extraDetail = nullptr;
			*this = other;
		}
		//copy assignment operator
		RideRequest& operator=(const RideRequest& other) {
			if (this != &other) {
				delete[] m_extraDetail;
				
				if (other.m_extraDetail) {
					m_extraDetail = new char[strlen(other.m_extraDetail) + 1];
					strcpy(m_extraDetail, other.m_extraDetail);
				} else{ // This if else statement added after my prof's feedback
					m_extraDetail = nullptr;
				}
				strcpy(m_customer, other.m_customer);
				m_price = other.m_price;
				m_discount = other.m_discount;
			}
			return *this;
		}
		//destructor
		~RideRequest() {
			delete[] m_extraDetail;
		}

		std::istream& read(std::istream& is);

		void display() const; //'const' added after my prof's feedback


	};

}



#endif //SDDS_RIDEREQUEST_H
