/***********************************************************************
// OOP244 Menu Module
// File	Menu.cpp
// Version 1.0
// Date	July 12 2023
// Author Eric Jo
// Description Milestone 1
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

#define CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds{

MenuItem::MenuItem() {
	m_content = nullptr;
}

MenuItem::MenuItem(const char* itemName) {
	m_content = nullptr;
	m_content = new char[strLen(itemName) + 1];
	strCpy(m_content, itemName);
}

//Returns the address of the content that the current object contains
const char* MenuItem::getContent() const {
	return m_content;
}

MenuItem:: ~MenuItem() {
	delete[] m_content;
}

//Returns true if the object is vaild
MenuItem::operator bool() const {
	return (m_content != nullptr && strLen(m_content) > 0);
}

//Returns the address of the content that current object contains
MenuItem::operator const char* () const {
	return (const char*)m_content;
}

//Display content
void MenuItem::display() const {
	if ((m_content != nullptr && strLen(m_content) > 0)) {
		cout << m_content;
	}
}


//Definition of Menu class

Menu::Menu() {
	m_title = nullptr;
	m_noOfItems = 0;
	for (unsigned i = 0; i < MAX_MENU_ITEMS; i++) {
		m_menuItems[i] = nullptr;
	}
}
Menu::Menu(const char* menuTitle) {
	m_title = nullptr;
	m_noOfItems = 0;
	for (unsigned i = 0; i < MAX_MENU_ITEMS; i++) {
		m_menuItems[i] = nullptr;
	}
	if (menuTitle != nullptr) {
		m_title = new MenuItem(menuTitle);
		for (unsigned i = 0; i < MAX_MENU_ITEMS; i++) {
			m_menuItems[i] = nullptr;
		}
	}
}

Menu::~Menu() {
	if (m_title != nullptr) {
		delete m_title;
	}
	for (unsigned i = 0; i < m_noOfItems; i++) {
		if (m_menuItems[i] != nullptr) {
			delete m_menuItems[i];
			m_menuItems[i] = nullptr;
		}
	}

}

//Display title with ":" at the end
void Menu::displayTitle(std::ostream& os)const {
	if (m_title != nullptr) {
		os << m_title->getContent() << ":" << endl;
	}
}

//Display only title
void Menu::displayTitle2(std::ostream& os) const {
	if (m_title != nullptr) {
		os << m_title->getContent();
	}
}

//Displays menus with a title on the top
void Menu::displayMenus(std::ostream& os)const {

	displayTitle(os);
	for (unsigned int i = 0; i < m_noOfItems; i++) {
		os << " " << i + 1 << "- ";
		os << m_menuItems[i]->getContent() << endl;
	}
	os << " 0- Exit" << endl;
	os << "> ";
}

//Displays Menus and receive user's selection
unsigned Menu::run() const  {
	displayMenus(std::cout);

	unsigned selection;
	while (!(std::cin >> selection) || selection < 0 || selection > m_noOfItems) {
		cin.clear();
		clearInputBuffer(std::cin);
		cout << "Invalid Selection, try again: ";
	}

	return selection;
}

//Same as run()
unsigned Menu::operator~() {
	return run();
}

//Assigns string address to a position of m_menuItems array
Menu& Menu::operator<<(const char* menuitemContent) {
	
	if (m_noOfItems < MAX_MENU_ITEMS) {
		m_menuItems[m_noOfItems] = new MenuItem(menuitemContent);
		m_noOfItems++;
	}
	return *this;
}

//Returns the number of contents
Menu::operator int()const {
	return m_noOfItems;
}

//Returns the unsigned number of contents
Menu::operator unsigned int()const {
	return m_noOfItems;
}

//Returns true if the object is valid
Menu::operator bool()const {
	return (m_noOfItems > 0);
}

//Display just title
std::ostream& operator<<(std::ostream& os, const Menu& Menu) {
	Menu.displayTitle2(os);
	return os;
}

//Returns contents matched to the position in m_menuItems array. If the position has no value, returns the value in the first position
const char* Menu::operator[](unsigned index) const {
	if (index < m_noOfItems) {
		return m_menuItems[index]->getContent();
	}
	else {
		return m_menuItems[0]->getContent();
	}
}
}