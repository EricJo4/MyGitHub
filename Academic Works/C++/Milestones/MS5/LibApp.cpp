/***********************************************************************
// OOP244 Menu Module
// File	LibApp.cpp
// Version 1.1
// Date	July 18 2023
// Author Eric Jo
// Description Milestone 5
//
// Revision History
// -----------------------------------------------------------
// Name Eric Jo         Date Aug 6, 2023         Reason Edit functions for Milestone 5
//
/////////////////////////////////////////////////////////////////
I have done all the coding by myselfand only copied the code
that my professor provided to complete my workshopsand assignments.
------------------------------------------------------------
***********************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "LibApp.h"
#include "PublicationSelector.h"
#include "Utils.h"

using namespace std;

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
		ifstream fin(m_filename);
		char pubType;
		for (int i = 0; fin && i < SDDS_LIBRARY_CAPACITY; i++) {
			fin >> pubType;
			fin.ignore();
			if (fin) {
				if (pubType == 'P') {
					m_PPA[i] = new Publication;
				}
				else if (pubType == 'B') {
					m_PPA[i] = new Book;
				}
				if (m_PPA[i]) {
					fin >> *m_PPA[i];
					m_NOLP++;
					m_LLRN = m_PPA[i]->getRef();
				}
			}
		}
	}

	void LibApp::save() {
		std::cout << "Saving Data";
		ofstream fout(m_filename);
		if (fout) {
			for (int i = 0; i < m_NOLP; i++) {
				if (m_PPA[i]->getRef() != 0) {
					fout << *m_PPA[i] << std::endl;
				}
			}
		}
		fout.close();
	}
	int LibApp::search(int searchType) {
		char title[256];
		int selectedType = 0, libRef = 0;
		char typeChar;
		PublicationSelector selector("Select one of the following found matches:", 15);

		selectedType = m_publicationTypeMenu.run();
		if (selectedType == 1) {
			typeChar = 'B';
		}
		else if (selectedType == 2) {
			typeChar = 'P';
		}

		cin.ignore(1000, '\n');
		cout << "Publication Title: ";
		cin.getline(title, 256);

		if (searchType == 1) {
			for (int i = 0; i < m_NOLP; i++) {
				if (m_PPA[i]->operator==(title) && typeChar == m_PPA[i]->type() && m_PPA[i]->getRef() != 0) {
					selector << m_PPA[i];
				}
			}
		}
		else if (searchType == 2) {
			for (int i = 0; i < m_NOLP; i++) {
				if (m_PPA[i]->operator==(title) && m_PPA[i]->onLoan() && typeChar == m_PPA[i]->type() && m_PPA[i]->getRef() != 0) {
					selector << m_PPA[i];
				}
			}
		}
		else if (searchType == 3) {
			for (int i = 0; i < m_NOLP; i++) {
				if (m_PPA[i]->operator==(title) && !m_PPA[i]->onLoan() && typeChar == m_PPA[i]->type() && m_PPA[i]->getRef() != 0) {
					selector << m_PPA[i];
				}
			}
		}

		if (selector) {
			selector.sort();
			libRef = selector.run();

			if (libRef > 0) {
				cout << *getPub(libRef) << endl;
			}
			else {
				cout << "Aborted!" << endl;
			}
		}
		else {
			cout << "No matches found!" << endl << endl;
		}
		return libRef;
	}

	Publication* LibApp::getPub(int libRef) {
		Publication* result = nullptr;
		for (int i = 0; i < m_NOLP; i++)
		{
			if (m_PPA[i]->getRef() == libRef) {
				result = m_PPA[i];
			}
		}

		return result;
	}
	void LibApp::returnPub() {
		bool aborted = false;
		cout << "Return publication to the library" << endl;
		int libRef = search(2);
		if (!(libRef > 0)) {
			aborted = true;
		}

		if (!aborted) {
			bool confirmed = confirm("Return Publication?");

			if (confirmed) {
				int daysLoaned = Date() - getPub(libRef)->checkoutDate();

				if (daysLoaned > SDDS_MAX_LOAN_DAYS) {
					double penalty = (daysLoaned - SDDS_MAX_LOAN_DAYS) * 0.5;
					cout << fixed << setprecision(2);
					cout << "Please pay $" << penalty << " penalty for being " << (daysLoaned - SDDS_MAX_LOAN_DAYS) << " days late!" << endl;
				}
				getPub(libRef)->set(0);
				m_changed = true;
			}
			cout << "Publication returned" << endl;
		}
		cout << endl;
	}

	void LibApp::newPublication() {
		bool aborted = false;

		if (m_NOLP == SDDS_LIBRARY_CAPACITY) {
			cout << "Library is at its maximum capacity!" << endl;
			aborted = true;
		}

		if (!aborted) {
			cout << "Adding new publication to the library" << endl;

			int pubType = m_publicationTypeMenu.run();
			cin.ignore(1000, '\n');

			Publication* p = nullptr;

			if (pubType == 0) {
				cout << "Aborted!" << endl;
				aborted = true;
			}
			else if (pubType == 1) {
				p = new Book;
				cin >> *p;
			}

			else if (pubType == 2) {
				p = new Publication;
				cin >> *p;
			}

			if (cin.fail()) {
				cin.ignore(1000, '\n');
				cin.clear();
				cout << "Aborted!" << endl;
				exit(0);
			}
			else {
				if (!aborted && confirm("Add this publication to the library?")) {
					if (!*p) {
						cout << "Failed to add publication!" << endl;
						delete p;
					}

					else {
						m_LLRN++;
						p->setRef(m_LLRN);

						m_PPA[m_NOLP] = p;
						m_NOLP++;
						m_changed = true;

						cout << "Publication added" << endl;
					}
				}
			}
		}
		cout << endl;
	}
	void LibApp::removePublication() {
		std::cout << "Removing publication from the library" << std::endl;
		int libRef = search(1);
		if(libRef) {
			if (confirm("Remove this publication from the library?")) {
				getPub(libRef)->setRef(0);
				m_changed = true;
				std::cout << "Publication removed" << std::endl;
			}
		}
		std::cout << std::endl;
	}

	void LibApp::checkOutPub() {
		cout << "Checkout publication from the library" << endl;
		int libRef = search(3);
		if (libRef > 0) {
			bool confirmed = confirm("Check out publication?");
			if (confirmed) {
				cout << "Enter Membership number: ";
				int inputMembership = getIntegerInput(10000, 99999);

				getPub(libRef)->set(inputMembership);

				m_changed = true;
				cout << "Publication checked out" << endl;
			}
			cout << endl;
		}
	}

	//Set the title of m_mainMenu and m_exitMenu
	LibApp::LibApp(const char* filename) : m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_NOLP(0), m_publicationTypeMenu("Choose the type of publication:"){
		if (filename) {
			strCpy(m_filename, filename);
		}
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		
		m_publicationTypeMenu << "Book" << "Publication";
		load();
	}

	LibApp::~LibApp() {
		for (int i = 0; i < m_NOLP; i++) {
			delete m_PPA[i];
		}
	}

	//Run Menu selection
	void LibApp::run() {
		int userInputMenu, userInputExit;

		do {
			userInputMenu = m_mainMenu.run();

			// Calling appropriate methods according to the choice of the user in the main menu
			if (userInputMenu == 0) {
				if (m_changed == true) {
					userInputExit = m_exitMenu.run();

					// Carrying out options according to the choice of user in the exit menu
					if (userInputExit == 0) {
						if (confirm("This will discard all the changes are you sure?")) {
							m_changed = false;
						}
					}
					else if (userInputExit == 1) {
						save();
					}
					else if (userInputExit == 2) {
						userInputMenu = 1;
					}
				}
				std::cout << std::endl;
			}
			else if (userInputMenu == 1) {
				newPublication();
			}
			else if (userInputMenu == 2) {
				removePublication();
			}
			else if (userInputMenu == 3) {
				checkOutPub();
			}
			else if (userInputMenu == 4) {
				returnPub();
			}
		} while (userInputMenu != 0);
		std::cout << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "Thanks for using Seneca Library Application" << std::endl;
	}

}