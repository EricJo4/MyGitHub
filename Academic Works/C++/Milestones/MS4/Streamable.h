/***********************************************************************
// OOP244 Streamable Module
// File	Streamable.h
// Version 1.0
// Date July 28 2023
// Author Eric Jo
// Description Milestone 4
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
***********************************************************************/

#ifndef SDDS_STEREAMABLE_H__
#define SDDS_STEREAMABLE_H__
#include <iostream>
namespace sdds {

	//Interface
	class Streamable {
	public:
		virtual std::ostream& write(std::ostream& os)const = 0;
		virtual std::istream& read(std::istream& in) = 0;
		virtual bool conIO(std::ios& io)const = 0;
		virtual operator bool() const = 0;
		virtual ~Streamable() {};
	};

	std::ostream& operator <<(std::ostream& os, const Streamable& st );
	std::istream& operator >>(std::istream& in, Streamable& st);
}

#endif //!SDDS_STREAMABLE_H__