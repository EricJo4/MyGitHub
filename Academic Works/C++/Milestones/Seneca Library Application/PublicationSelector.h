/***********************************************************************
// OOP244 PublicationSelector Module
// File	PublicationSelector.h
// Version 1.0
// Date August 5 2023
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

#ifndef SDDS_PUBLICATIONSELECTOR_H__
#define SDDS_PUBLICATIONSELECTOR_H__
#include "Publication.h"
#include "Book.h"
namespace sdds {
	class PublicationSelector {
		const char* m_title;
		const Publication** m_publications;
		int m_size;
		int m_noOfMatches;

	public:
		PublicationSelector(const char* title, int size);
		~PublicationSelector();
		PublicationSelector& operator+=(const Publication* pub);
		operator bool() const;
		int run() const;
		void sort();
		PublicationSelector& operator<<(const Publication* pub);
	};
	
}


#endif //!SDDS_PUBLICATIONSELECTOR_H__