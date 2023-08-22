/***********************************************************************
// OOP244 Publication Module
// File	Publication.h
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

#ifndef SDDS_PUBLICATION_H__
#define SDDS_PUBLICATION_H__
#include <iostream>
#include "Lib.h"
#include "Streamable.h"
#include "Date.h"

namespace sdds {


	class Publication : public Streamable {
		char* m_title; //title for the publication
		char m_shelfld[SDDS_SHELF_ID_LEN + 1]; // 4characters, hold the loctaion of the publication
		int m_membership; //0 or 5 digits, 0 means publication is available
		int m_libRef; //serial number to identify each publication
		Date m_date; // this date is used to keep the date on which the book was borrowed by the member.

	public:
		Publication();
		//inherited functions
		virtual ~Publication();
		virtual std::ostream& write(std::ostream& os)const;
		virtual std::istream& read(std::istream& in);
		virtual bool conIO(std::ios& io)const;
		virtual operator bool() const;

		//The Rule of three
		Publication(const Publication& pb);
		Publication& operator=(const Publication& pb);

		//Methods
		virtual void set(int member_id);
		// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);
		// Sets the **libRef** attribute value
		void resetDate();
		// Sets the date to the current date of the system.
		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;
		//Returns the date attribute
		bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;
		//Returns the title attribute
		int getRef()const;
		//Returns the libRef attirbute.

		void clear();
		void copy(const Publication& other);
	};
}


#endif // !SDDS_PUBLICATION_H__
