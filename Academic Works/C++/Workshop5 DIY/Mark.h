/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: June 16 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_MARK_H_
#define SDDS_MAKR_H_
#include <iostream>

namespace sdds {
	class Mark {
		int m_mark;
	public:
		Mark();
		Mark(int number);
		operator bool() const;
		operator int() const;
		operator double() const;
		operator char() const;
		Mark& operator = (int number);
		Mark& operator += (int number);
	};
	int operator+=(int& var, Mark& mark);
}




#endif //SDDS_MAKR_H_