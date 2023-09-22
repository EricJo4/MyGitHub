/***********************************************************************
// OOP244 Book Module
// File	Book.h
// Version 1.0
// Date August 1 2023
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
#include "Publication.h"


namespace sdds {
	class Book : public Publication {
		char* m_author;

	public:
		Book():m_author(nullptr) {}

		//Rule of Three
		Book(const Book& other);
		Book& operator=(const Book& other);
		~Book();

		virtual char type()const;
		virtual std::ostream& write(std::ostream& os)const;
		virtual std::istream& read(std::istream& in);
		virtual void set(int member_id);
		virtual operator bool() const;
	};
	
}