/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: July 24 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"

//inherits class Shape
namespace sdds {
	
	class LblShape : public Shape{
		char* m_label;
	protected:
		const char* label() const;
	public:
		
		LblShape() : m_label(nullptr) {}
		LblShape(const char* label);
		virtual ~LblShape();
		LblShape(const LblShape& lblShape) = delete;
		LblShape& operator =(const LblShape& lblShape) = delete;
		virtual void getSpecs(std::istream& in);
	};
}



#endif //SDDS_LBLSHAPE_H