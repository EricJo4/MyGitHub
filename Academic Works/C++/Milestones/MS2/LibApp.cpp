/***********************************************************************
// OOP244 Menu Module
// File	LibApp.cpp
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

#include<iostream>
#include"LibApp.h"

namespace sdds {
	//Menu::run() is used in this function
	bool LibApp::confirm(const char* message) {
		Menu menu(message);
		menu << "Yes";
		int selection = menu.run();
		return (selection == 1);
	}

	//functions for menu selection
	void LibApp::load() {
		std::cout << "Loading Data" << std::endl;
	}
	void LibApp::save() {
		std::cout << "Saving Data" << std::endl;
	}
	void LibApp::search() {
		std::cout << "Searching for publication" << std::endl;
	}
	void LibApp::returnPub() {
		search();
		std::cout << "Returning publication" << std::endl;
		std::cout << "Publication returned" << std::endl;
		std::cout << std::endl;
		m_changed = true;
	}
	void LibApp::newPublication() {
		std::cout << "Adding new publication to library" << std::endl;
		if (confirm("Add this publication to library?")) {
			m_changed = true;
			std::cout << "Publication added" << std::endl;
		}
		std::cout << std::endl;
	}
	void LibApp::removePublication() {
		std::cout << "Removing publication from library" << std::endl;
		search();
		if (confirm("Remove this publication from the library?")) {
			m_changed = true;
			std::cout << "Publication removed" << std::endl;
		}
		std::cout << std::endl;
	}

	void LibApp::checkOutPub() {
		search();
		if (confirm("Check out publication?")) {
			m_changed = true;
			std::cout << "Publication checked out" << std::endl;
			std::cout << std::endl;
		}
	}

	//Set the title of m_mainMenu and m_exitMenu
	LibApp::LibApp() : m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"){
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		load();
	}

	//Run Menu selection
	void LibApp::run() {
		bool completed = false;
		while (!completed) {
			unsigned selection = m_mainMenu.run();
			if (selection == 1) {
				newPublication();
			}
			else if (selection == 2) {
				removePublication();
			}
			else if (selection == 3) {
				checkOutPub();
			}
			else if (selection == 4) {
				returnPub();
			}
			else {
				if (m_changed) {
					unsigned exitSelection = m_exitMenu.run();
					if (exitSelection == 1) {
						save();
						completed = true;
					}
					else if (exitSelection == 2) {
						std::cout << std::endl;
					}
					else {
						if (confirm("This will discard all the changes are you sure?")) {
							completed = true;
						}
					}
				}
				else {
					completed = true;
				}
			}
		}
		std::cout << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "Thanks for using Seneca Library Application" << std::endl;
	}

}