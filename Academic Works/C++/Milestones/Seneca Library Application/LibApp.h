/***********************************************************************
// OOP244 Menu Module
// File	LibApp.h
// Version 1.0
// Date	July 18 2023
// Author Eric Jo
// Description Milestone 5
//
// Revision History
// -----------------------------------------------------------
// Name Eric Jo          Date Aug 6, 2023         Reason class members were edited for Milestone 5
//
/////////////////////////////////////////////////////////////////
I have done all the coding by myselfand only copied the code
that my professor provided to complete my workshopsand assignments.
------------------------------------------------------------
***********************************************************************/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Publication.h"

namespace sdds {
	class LibApp : public Menu {
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;

		char m_filename[256];
		Publication* m_PPA[SDDS_LIBRARY_CAPACITY]; // Publication Pointers Array
		int m_NOLP; // Number Of Loaded Publications
		int m_LLRN; // Last Library Reference Number


		Menu m_publicationTypeMenu;
		
		bool confirm(const char* message);
		void load();
		void save();
		int search(int searchType);
		void returnPub();
		void newPublication();
		void removePublication();
		void checkOutPub();
		Publication* getPub(int libRef);
	public:
		LibApp(const char* filename);
		~LibApp();
		void run();
	};
}


#endif // SDDS_LIBAPP_H