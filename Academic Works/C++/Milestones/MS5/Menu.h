/***********************************************************************
// OOP244 Menu Module
// File	Menu.h
// Version 1.0
// Date	July 17 2023
// Author Eric Jo
// Description Milestone 5
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
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>


namespace sdds {
	const unsigned MAX_MENU_ITEMS = 20;
	const unsigned MAX_NUM_OF_TITLE = 50;
	class MenuItem {
		char* m_content;
		MenuItem();
		MenuItem(const char* itemName);

		MenuItem(const MenuItem& menuitem) = delete;
		MenuItem& operator=(const MenuItem& menuitem) = delete;

		const char* getContent() const;
		virtual ~MenuItem();
		operator bool() const;
		operator const char* () const;
		void display() const;
		friend class Menu;
	};

	class Menu {
		MenuItem* m_title;
		MenuItem* m_menuItems[MAX_MENU_ITEMS];
		unsigned m_noOfItems;
	public:
		Menu();
		Menu(const char* menuTitle);
		~Menu();

		Menu(const Menu& menu) = delete;
		Menu& operator=(const Menu& menu) = delete;

		void displayTitle(std::ostream& os)const;
		void displayTitle2(std::ostream& os)const;
		void displayMenus(std::ostream& os)const;
		unsigned run()const;
		unsigned operator~();
		Menu& operator<<(const char* menuitemContent);
		operator int()const;
		operator unsigned int()const;
		operator bool()const;
		const char* operator[](unsigned index) const;
	};
	std::ostream& operator<<(std::ostream& os, const Menu& Menu);
}
#endif