/***********************************************************************
// OOP244 Streamable Module
// File	Streamable.cpp
// Version 1.0
// Date July 28 2023
// Author Eric Jo
// Description Milestone 5
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

#include "Streamable.h"

namespace sdds {
	std::ostream& operator <<(std::ostream& os, const Streamable& st) {
		return st.write(os);
	}

	std::istream& operator>>(std::istream& in, Streamable& st) {
		return st.read(in);
	}
}