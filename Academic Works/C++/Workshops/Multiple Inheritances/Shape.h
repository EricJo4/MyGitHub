/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: July 24 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>

//Interface
namespace sdds {
	class Shape {
	public:
		virtual void draw(std::ostream& os)const = 0;
		virtual void getSpecs(std::istream& in) = 0;
		virtual ~Shape() {}
	};
	std::istream& operator >> (std::istream& in, Shape& shape);
	std::ostream& operator << (std::ostream& os, const Shape& shape);
}


#endif //SDDS_SHAPE_H