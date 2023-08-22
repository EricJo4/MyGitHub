/***********************************************************************
// OOP244 Menu Module
// File	LibApp.h
// Version 1.0
// Date	July 18 2023
// Author Eric Jo
// Description Milestone 2
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
I have done all the coding by myselfand only copied the code
that my professor provided to complete my workshopsand assignments.
------------------------------------------------------------
***********************************************************************/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"

namespace sdds {
	class LibApp : public Menu {
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		bool confirm(const char* message);
		void load();
		void save();
		void search();
		void returnPub();
		void newPublication();
		void removePublication();
		void checkOutPub();
	public:
		LibApp();
		void run();
	};
}


#endif // SDDS_LIBAPP_H