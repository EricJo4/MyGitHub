/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: July 24 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"

//inherits class LblShape
namespace sdds {
	class Line : public LblShape {
		int m_length;
	public:
		Line() : LblShape(), m_length(0) {}
		Line(const char* label, int length) : LblShape(label), m_length(length) {}
		void getSpecs(std::istream& in);
		void draw(std::ostream& os)const;
	};
}



#endif //SDDS_LINE_H
