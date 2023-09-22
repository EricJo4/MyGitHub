/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: June 10 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Label.h"
#include "cstring.h"
using namespace std;

namespace sdds {
	void Label::setToDefault() {
		m_frameArg = new char[8 + 1];
		strCpy(m_frameArg, "+-+|+-+|");
		m_content = nullptr;
	}

	void Label::setFrame(const char* Cstr) {
		delete[] m_frameArg;
		if (Cstr != nullptr) {
			m_frameArg = new char[strLen(Cstr) + 1];
			strCpy(m_frameArg, Cstr);
		}
		
	}

	void Label::setContent(const char* Cstr) {
		if (Cstr != nullptr) {
			delete[] m_content;
			m_content = new char[strLen(Cstr) + 1];
			strCpy(m_content, Cstr);
		}

	}

	Label::Label() {
		setToDefault();
		
	}

	Label::Label(const char* frameArg) {
		setToDefault();
		setFrame(frameArg);
	}

	Label::Label(const char* frameArg, const char* content) {
		setToDefault();
		setFrame(frameArg);
		setContent(content);
	}

	Label::~Label() {
		delete[] m_frameArg;
		delete[] m_content;
	}

	void Label::readLabel() {
		char nameOfLabels[70 + 1];
		cout << "> ";
		cin.getline(nameOfLabels, 70+1);
		nameOfLabels[70] = '\0';
		setContent(nameOfLabels);
	}
	
	std::ostream& Label::printLabel()const{
		if (m_content != nullptr) {
			cout << m_frameArg[0];
			for (int i = 0; i < strLen(m_content) + 2; i++) {
				cout << m_frameArg[1];
			}
			cout << m_frameArg[2] << endl;

			cout << m_frameArg[7];
			for (int i = 0; i < strLen(m_content) + 2; i++) {
				cout << " ";
			}
			cout << m_frameArg[3] << endl;
			cout << m_frameArg[7] << " " << m_content << " " << m_frameArg[3] << endl;
			cout << m_frameArg[7];
			for (int i = 0; i < strLen(m_content) + 2; i++) {
				cout << " ";
			}
			cout << m_frameArg[3] << endl;
			cout << m_frameArg[6];
			for (int i = 0; i < strLen(m_content) + 2; i++) {
				cout << m_frameArg[5];
			}
			cout << m_frameArg[4];
		}
		return cout;
	}
}